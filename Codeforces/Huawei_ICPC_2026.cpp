/*
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
    In the name of Allah, the Most Gracious, the Most Merciful.
*/

// 67 67 67  six sevennnnnnnn
//  TTT

#include <bits/stdc++.h>
using namespace std;

static const int MAXR = 2005;
static const int MAXK = 9;

struct Table {
    vector<pair<double, double>> col[6];

    void addRow(double bs, const double v[6]) {
        for (int c = 0; c < 6; ++c)
            if (v[c] >= 0.0)
                col[c].push_back({bs, v[c]});
    }

    void finalize() {
        for (int c = 0; c < 6; ++c)
            sort(col[c].begin(), col[c].end());
    }

    double lookup(int c, double size) const {
        const auto &pts = col[c];
        if (pts.empty()) return 1.0;
        if (size <= pts.front().first) return pts.front().second;
        if (size >= pts.back().first) return pts.back().second;

        int lo = 0, hi = (int)pts.size() - 1;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            if (pts[mid].first <= size) lo = mid;
            else hi = mid;
        }

        double x0 = pts[lo].first, y0 = pts[lo].second;
        double x1 = pts[hi].first, y1 = pts[hi].second;
        if (x1 == x0) return y0;

        double frac = (size - x0) / (x1 - x0);
        return y0 + frac * (y1 - y0);
    }
};

int K;
double S, latency_in_ms, bandwidth_gbps;
long long bytes_per_token;
int num_layers;

double SLO1, SLO2, tp_UB, tp_base, dist_base, w_tp, w_c;
Table table;

int Lin[MAXR];
double arrivalT[MAXR];
double gapStart[MAXR];
int remoteOf_[MAXR];
bool active[MAXR];

int activeResidents[MAXK];
double remoteReady[MAXK];

int inFlightUp[MAXK];
double inFlightUpWork[MAXK];
double inFlightDecWork[MAXK];

// P_PROC SPLIT (candidate): tracks a P_PROC that was deliberately split
// into two pieces so a ready D_PROC batch could run in between, rather
// than sitting blocked behind one long unsplit prefill computation.
// -1 means no split in progress on that remote. At most one split per
// request, ever -- the remote always finishes the second (final) piece
// unconditionally the next time it's free, so a request can be deferred
// for at most one D_PROC opportunity, never indefinitely.
int pprocResumeRid[MAXK];
int pprocResumePos[MAXK];

deque<int> qPPre;
deque<int> qPPost;
deque<int> qPProc[MAXK];
deque<int> qDPre;
deque<int> qDPost;
deque<int> qDProc[MAXK];

bool freeE = true;
bool freeC[MAXK];

double now_t = 0.0;

static const double POST_BONUS       = 0.06;
static const double ADM_IDLE_BONUS   = 1.0;
static const double DECODE_TP_BONUS  = 0.12;
static const double PREFILL_TP_BONUS = 0.04;

inline double urg1(int rid) {
    double age = now_t - arrivalT[rid];
    if (age <= SLO1) return 0.0;
    return (age - SLO1) / SLO1;
}

inline double urg2(int rid) {
    double age = now_t - gapStart[rid];
    if (age <= SLO2) return 0.0;
    return (age - SLO2) / SLO2;
}

double topKAveUrg2(const deque<int>& q) {
    int m = (int)q.size();
    if (m == 0) return 0.0;

    int k = max(1, (int)sqrt((double)m));
    if (k > m) k = m;

    double sum = 0.0;
    int idx = 0;
    for (int id : q) {
        sum += urg2(id);
        ++idx;
        if (idx >= k) break;
    }
    return sum / (double)k;
}

int pickBestRemoteFor(int /*rid*/) {
    int best = 0;
    double bestReady = 1e100;

    for (int k = 0; k < K; ++k) {
        double ready = max(now_t, remoteReady[k]);

        ready += inFlightUpWork[k];
        ready += inFlightDecWork[k];

        for (int id : qPProc[k]) {
            ready += S + table.lookup(1, (double)Lin[id]);
        }

        if (!qDProc[k].empty()) {
            int m = (int)qDProc[k].size();
            ready += S + table.lookup(4, (double)m);
        }

        if (ready < bestReady) {
            bestReady = ready;
            best = k;
        } else if (ready == bestReady) {
            if (activeResidents[k] < activeResidents[best]) {
                best = k;
            }
        }
    }

    return best;
}

void eraseFromQueue(deque<int>& q, int id) {
    for (auto it = q.begin(); it != q.end(); ++it) {
        if (*it == id) {
            q.erase(it);
            return;
        }
    }
}

// Marks a D_PRE group's future decode work as already committed to each
// remote it touches, before it becomes visible in qDProc.
//
// CORRECTED from the earlier attempt: that version added a full
// S + duration(batch=1) for EVERY member, which double-counts S -- S is
// only paid once per eventual batch task, not once per member, under
// full batching. This adds S exactly once per remote represented in the
// group, plus a small per-member marginal duration (the slope of the
// decode_proc column near batch size 1-2, not a whole size-1 task's
// duration), which is a much closer approximation of the real
// incremental cost.
void markDPreDispatched(const deque<int>& q) {
    if (q.empty()) return;
    static int cnt[MAXK];
    for (int k = 0; k < K; ++k) cnt[k] = 0;
    for (int r : q) {
        int k = remoteOf_[r];
        if (k >= 0 && k < K) cnt[k]++;
    }
    double marginal = table.lookup(4, 2.0) - table.lookup(4, 1.0);
    if (marginal < 0.0) marginal = 0.0;
    for (int k = 0; k < K; ++k) {
        if (cnt[k] > 0) {
            inFlightDecWork[k] += S + marginal * (double)cnt[k];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> S >> latency_in_ms >> bandwidth_gbps >> bytes_per_token >> num_layers;
    cin >> SLO1 >> SLO2 >> tp_UB >> tp_base >> dist_base >> w_tp >> w_c;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        double bs;
        double v[6];
        cin >> bs >> v[0] >> v[1] >> v[2] >> v[3] >> v[4] >> v[5];
        table.addRow(bs, v);
    }
    table.finalize();

    for (int k = 0; k < K; ++k) {
        freeC[k] = true;
        activeResidents[k] = 0;
        remoteReady[k] = 0.0;
        inFlightUp[k] = 0;
        inFlightUpWork[k] = 0.0;
        inFlightDecWork[k] = 0.0;
        pprocResumeRid[k] = -1;
        pprocResumePos[k] = 0;
    }

    for (int i = 0; i < MAXR; ++i) {
        active[i] = false;
        remoteOf_[i] = -1;
        arrivalT[i] = 0.0;
        gapStart[i] = 0.0;
        Lin[i] = 0;
    }

    const bool aggressiveThroughput = (w_tp > 0.6 && w_c < 0.4);
    const bool waitingDominant      = (w_c >= 0.4);

    vector<char> starvedPProcJustRun(K, 0);

    vector<int> dpostDoneThisFrame;
    vector<int> finThisFrame;

    string tok;
    while (cin >> tok) {
        if (tok == "END") break;

        now_t = stod(tok);
        int e;
        cin >> e;

        dpostDoneThisFrame.clear();
        finThisFrame.clear();

        for (int i = 0; i < e; ++i) {
            string etype;
            cin >> etype;

            if (etype == "ARR") {
                int rid;
                long long lin;
                cin >> rid >> lin;

                Lin[rid] = (int)lin;
                arrivalT[rid] = now_t;
                active[rid] = true;
                qPPre.push_back(rid);

            } else if (etype == "TDN") {
                string server, cmd, subcmd;
                cin >> server >> cmd >> subcmd;

                if (server == "E") {
                    freeE = true;
                } else {
                    int k = stoi(server.substr(1));
                    freeC[k] = true;
                    remoteReady[k] = now_t;
                }

                if (cmd == "P") {
                    if (subcmd == "PRE") {
                        int remote, rid;
                        double dur;
                        cin >> remote >> rid >> dur;

                    } else if (subcmd == "PROC") {
                        int ls, le, remote, rid;
                        double dur;
                        cin >> ls >> le >> remote >> rid >> dur;

                    } else {
                        int remote, rid;
                        double dur;
                        cin >> remote >> rid >> dur;

                        gapStart[rid] = now_t;
                        qDPre.push_back(rid);
                    }

                } else {
                    if (subcmd == "PRE") {
                        int marker, m;
                        cin >> marker >> m;
                        for (int j = 0; j < m; ++j) {
                            int x;
                            cin >> x;
                        }
                        double dur;
                        cin >> dur;

                    } else if (subcmd == "PROC") {
                        int remote, m;
                        cin >> remote >> m;
                        for (int j = 0; j < m; ++j) {
                            int x;
                            cin >> x;
                        }
                        double dur;
                        cin >> dur;

                    } else {
                        int marker, m;
                        cin >> marker >> m;
                        for (int j = 0; j < m; ++j) {
                            int x;
                            cin >> x;
                            dpostDoneThisFrame.push_back(x);
                        }
                        double dur;
                        cin >> dur;
                    }
                }

            } else if (etype == "XDN") {
                string dir;
                int remote;
                long long size;
                string tag;
                int m;

                cin >> dir >> remote >> size >> tag >> m;

                static vector<int> rids;
                rids.clear();
                rids.reserve(m);

                for (int j = 0; j < m; ++j) {
                    int x;
                    cin >> x;
                    rids.push_back(x);
                }

                if (tag == "PRE") {
                    int rid = rids[0];
                    if (dir == "UP") {
                        qPProc[remote].push_back(rid);

                        if (inFlightUp[remote] > 0) {
                            --inFlightUp[remote];
                        }

                        inFlightUpWork[remote] = max(
                            0.0,
                            inFlightUpWork[remote]
                            - (S + table.lookup(1, (double)Lin[rid]))
                        );
                    } else {
                        qPPost.push_back(rid);
                    }

                } else {
                    if (dir == "UP") {
                        // Mirrors markDPreDispatched exactly: this transfer
                        // is precisely one remote's slice of one D_PRE
                        // dispatch, so it removes exactly what that call
                        // added for this remote.
                        double marginal = table.lookup(4, 2.0) - table.lookup(4, 1.0);
                        if (marginal < 0.0) marginal = 0.0;
                        double dec = S + marginal * (double)rids.size();
                        for (int r : rids) qDProc[remote].push_back(r);
                        inFlightDecWork[remote] = max(0.0, inFlightDecWork[remote] - dec);
                    } else {
                        for (int r : rids) qDPost.push_back(r);
                    }
                }

            } else if (etype == "FIN") {
                int rid;
                cin >> rid;
                finThisFrame.push_back(rid);
            }
        }

        if (!dpostDoneThisFrame.empty()) {
            static vector<char> finMark(MAXR, 0);

            for (int r : finThisFrame) finMark[r] = 1;

            for (int r : dpostDoneThisFrame) {
                if (finMark[r]) {
                    active[r] = false;
                    if (remoteOf_[r] >= 0) {
                        activeResidents[remoteOf_[r]]--;
                    }
                    finMark[r] = 0;
                } else {
                    gapStart[r] = now_t;
                    qDPre.push_back(r);
                }
            }
        }

        vector<string> lines;

        // ---------------- local computer E ----------------
        if (freeE) {
            if (waitingDominant) {
                int bestType = -1;
                int bestId = -1;
                double bestDeadline = 1e100;

                for (int id : qPPre) {
                    double dl = arrivalT[id] + SLO1;
                    if (dl < bestDeadline) { bestDeadline = dl; bestType = 0; bestId = id; }
                }
                for (int id : qPPost) {
                    double dl = arrivalT[id] + SLO1;
                    if (dl < bestDeadline) { bestDeadline = dl; bestType = 1; bestId = id; }
                }
                for (int id : qDPre) {
                    double dl = gapStart[id] + SLO2;
                    if (dl < bestDeadline) { bestDeadline = dl; bestType = 2; bestId = id; }
                }
                for (int id : qDPost) {
                    double dl = gapStart[id] + SLO2;
                    if (dl < bestDeadline) { bestDeadline = dl; bestType = 3; bestId = id; }
                }

                if (bestType == 0) {
                    int rid = bestId;
                    eraseFromQueue(qPPre, rid);

                    int k = pickBestRemoteFor(rid);
                    remoteOf_[rid] = k;
                    activeResidents[k]++;
                    inFlightUp[k]++;
                    inFlightUpWork[k] += S + table.lookup(1, (double)Lin[rid]);

                    lines.push_back("E P PRE " + to_string(k) + " " + to_string(rid));
                    freeE = false;

                } else if (bestType == 1) {
                    int rid = bestId;
                    eraseFromQueue(qPPost, rid);

                    lines.push_back("E P POST " + to_string(remoteOf_[rid]) + " " + to_string(rid));
                    freeE = false;

                } else if (bestType == 2) {
                    string line = "E D PRE -1 " + to_string(qDPre.size());
                    for (int r : qDPre) line += ' ' + to_string(r);
                    lines.push_back(move(line));
                    markDPreDispatched(qDPre);
                    qDPre.clear();
                    freeE = false;

                } else if (bestType == 3) {
                    string line = "E D POST -1 " + to_string(qDPost.size());
                    for (int r : qDPost) line += ' ' + to_string(r);
                    lines.push_back(move(line));
                    qDPost.clear();
                    freeE = false;
                }

            } else if (aggressiveThroughput) {
                bool anyIdleRemote = false;
                for (int k = 0; k < K; ++k) {
                    if (freeC[k] && qPProc[k].empty() && qDProc[k].empty()) {
                        anyIdleRemote = true;
                        break;
                    }
                }

                bool prefillStarved = false;
                for (int k = 0; k < K; ++k) {
                    if (qPProc[k].empty() && inFlightUp[k] == 0) {
                        prefillStarved = true;
                        break;
                    }
                }

                double sc_ppre = -1e18, sc_ppost = -1e18, sc_dpre = -1e18, sc_dpost = -1e18;

                if (!qPPre.empty()) {
                    int b = qPPre.front();
                    if (prefillStarved) {
                        sc_ppre = w_c * urg1(b) + w_tp * 0.20;
                    } else {
                        sc_ppre = w_c * urg1(b) + w_tp * (anyIdleRemote ? ADM_IDLE_BONUS : PREFILL_TP_BONUS);
                    }
                }

                if (!qPPost.empty()) {
                    int b = qPPost.front();

                    // ANTI-STARVATION: P_PRE gets w_tp*ADM_IDLE_BONUS
                    // (1.0) whenever a remote is idle, and D_PRE now gets
                    // w_tp*1.20 in that same situation (the fix that
                    // gained +28 points). P_POST has never gotten any
                    // such boost -- its score is a small flat constant
                    // (POST_BONUS + w_tp*PREFILL_TP_BONUS). At typical
                    // aggressiveThroughput weights that's roughly 10x
                    // smaller than what P_PRE/D_PRE get when idle, so
                    // whenever a remote is idle, P_POST can lose the
                    // priority race every single time.
                    //
                    // That matters because P_POST is what unblocks D_PRE
                    // in the first place (P_POST completion is what
                    // pushes a request into qDPre) -- so a starved P_POST
                    // can mean D_PRE's own idle-remote boost has nothing
                    // new to batch, partially offsetting that fix's
                    // benefit. This only activates once a real backlog
                    // (>=2 waiting) is visible, so it can't change
                    // behavior in the common case where P_POST already
                    // gets serviced promptly.
                    double postBonus = PREFILL_TP_BONUS;
                    if ((int)qPPost.size() >= 2) postBonus = 1.0;

                    sc_ppost = w_c * urg1(b) + POST_BONUS + w_tp * postBonus;
                }

                if (!qDPre.empty()) {
                    int b = qDPre.front();

                    // EXPERIMENT: when a remote is about to become idle,
                    // dispatch decode preparation before admitting new work
                    // or before doing local D_POST. This prevents starvation
                    // of remote computers in throughput-heavy regimes.
                    double tpNum = DECODE_TP_BONUS;
                    if (anyIdleRemote) tpNum = 1.20;

                    sc_dpre = w_c * urg2(b) + w_tp * tpNum;
                }

                if (!qDPost.empty()) {
                    int b = qDPost.front();
                    sc_dpost = w_c * urg2(b) + POST_BONUS + w_tp * DECODE_TP_BONUS;
                }

                int choice = -1;
                double best = -1e18;
                if (!qPPre.empty()  && sc_ppre  > best) { best = sc_ppre;  choice = 0; }
                if (!qPPost.empty() && sc_ppost > best) { best = sc_ppost; choice = 1; }
                if (!qDPre.empty()  && sc_dpre  > best) { best = sc_dpre;  choice = 2; }
                if (!qDPost.empty() && sc_dpost > best) { best = sc_dpost; choice = 3; }

                if (choice == 3) {
                    string line = "E D POST -1 " + to_string(qDPost.size());
                    for (int r : qDPost) line += ' ' + to_string(r);
                    lines.push_back(move(line));
                    qDPost.clear();
                    freeE = false;

                } else if (choice == 1) {
                    int rid = qPPost.front();
                    qPPost.pop_front();
                    lines.push_back("E P POST " + to_string(remoteOf_[rid]) + " " + to_string(rid));
                    freeE = false;

                } else if (choice == 2) {
                    string line = "E D PRE -1 " + to_string(qDPre.size());
                    for (int r : qDPre) line += ' ' + to_string(r);
                    lines.push_back(move(line));
                    markDPreDispatched(qDPre);
                    qDPre.clear();
                    freeE = false;

                } else if (choice == 0) {
                    int rid = qPPre.front();
                    qPPre.pop_front();

                    int k = pickBestRemoteFor(rid);
                    remoteOf_[rid] = k;
                    activeResidents[k]++;
                    inFlightUp[k]++;
                    inFlightUpWork[k] += S + table.lookup(1, (double)Lin[rid]);

                    lines.push_back("E P PRE " + to_string(k) + " " + to_string(rid));
                    freeE = false;
                }

            } else {
                // Mixed branch, currently unreachable because the two
                // active branches partition the entire weight space.
                bool anyIdleRemote = false;
                for (int k = 0; k < K; ++k) {
                    if (freeC[k] && qPProc[k].empty() && qDProc[k].empty()) {
                        anyIdleRemote = true;
                        break;
                    }
                }

                int bestType = -1;
                double bestPriority = -1e18;
                vector<int> bestIds;

                if (!qPPost.empty()) {
                    int rid = qPPost.front();
                    double score = w_c * urg1(rid) + POST_BONUS + w_tp * PREFILL_TP_BONUS;
                    double dur = S + table.lookup(2, (double)Lin[rid]);
                    double pri = score / dur;
                    if (pri > bestPriority) { bestPriority = pri; bestType = 1; bestIds = {rid}; }
                }

                if (!qDPre.empty()) {
                    int m = (int)qDPre.size();
                    double score = w_c * topKAveUrg2(qDPre) + w_tp * DECODE_TP_BONUS;
                    double dur = S + table.lookup(3, (double)m);
                    double pri = score / dur;
                    if (pri > bestPriority) { bestPriority = pri; bestType = 2; }
                }

                if (!qDPost.empty()) {
                    int m = (int)qDPost.size();
                    double score = w_c * topKAveUrg2(qDPost) + POST_BONUS + w_tp * DECODE_TP_BONUS;
                    double dur = S + table.lookup(5, (double)m);
                    double pri = score / dur;
                    if (pri > bestPriority) { bestPriority = pri; bestType = 3; }
                }

                if (!qPPre.empty()) {
                    int rid = qPPre.front();
                    double score = w_c * urg1(rid) + w_tp * (anyIdleRemote ? ADM_IDLE_BONUS : PREFILL_TP_BONUS);
                    double dur = S + table.lookup(0, (double)Lin[rid]);
                    double pri = score / dur;
                    if (pri > bestPriority) { bestPriority = pri; bestType = 0; bestIds = {rid}; }
                }

                if (bestType == 3) {
                    string line = "E D POST -1 " + to_string(qDPost.size());
                    for (int r : qDPost) line += ' ' + to_string(r);
                    lines.push_back(move(line));
                    qDPost.clear();
                    freeE = false;
                } else if (bestType == 2) {
                    string line = "E D PRE -1 " + to_string(qDPre.size());
                    for (int r : qDPre) line += ' ' + to_string(r);
                    lines.push_back(move(line));
                    markDPreDispatched(qDPre);
                    qDPre.clear();
                    freeE = false;
                } else if (bestType == 1) {
                    int rid = bestIds[0];
                    qPPost.pop_front();
                    lines.push_back("E P POST " + to_string(remoteOf_[rid]) + " " + to_string(rid));
                    freeE = false;
                } else if (bestType == 0) {
                    int rid = bestIds[0];
                    qPPre.pop_front();

                    int k = pickBestRemoteFor(rid);
                    remoteOf_[rid] = k;
                    activeResidents[k]++;
                    inFlightUp[k]++;
                    inFlightUpWork[k] += S + table.lookup(1, (double)Lin[rid]);

                    lines.push_back("E P PRE " + to_string(k) + " " + to_string(rid));
                    freeE = false;
                }
            }
        }

        // ---------------- remote computers ----------------
        for (int k = 0; k < K; ++k) {
            if (!freeC[k]) continue;

            if (waitingDominant) {
                int pId = -1; double pDl = 1e100;
                for (int id : qPProc[k]) {
                    double dl = arrivalT[id] + SLO1;
                    if (dl < pDl) { pDl = dl; pId = id; }
                }
                double dDl = 1e100;
                for (int id : qDProc[k]) {
                    double dl = gapStart[id] + SLO2;
                    if (dl < dDl) dDl = dl;
                }

                bool hasP = !qPProc[k].empty(), hasD = !qDProc[k].empty();
                double durP = hasP ? table.lookup(1, (double)Lin[pId]) : 0.0;
                int mD = (int)qDProc[k].size();
                double durD = hasD ? table.lookup(4, (double)mD) : 0.0;

                double laxP = hasP ? (pDl - now_t - durP) : 1e100;
                double laxD = hasD ? (dDl - now_t - durD) : 1e100;
                double minLax = min(laxP, laxD);

                int bestType = -1;
                int bestId = -1;

                if (minLax < 0.0) {
                    double bestDeadline = 1e100;
                    if (hasP && pDl < bestDeadline) { bestDeadline = pDl; bestType = 0; bestId = pId; }
                    if (hasD && dDl < bestDeadline) { bestDeadline = dDl; bestType = 1; }
                } else {
                    double bestDensity = -1.0;
                    if (hasP) { double d = 1.0 / durP; if (d > bestDensity) { bestDensity = d; bestType = 0; bestId = pId; } }
                    if (hasD) { double d = (double)mD / durD; if (d > bestDensity) { bestDensity = d; bestType = 1; } }
                }

                if (bestType == 0) {
                    int rid = bestId;
                    eraseFromQueue(qPProc[k], rid);

                    lines.push_back("C" + to_string(k) + " P PROC 0 " + to_string(num_layers) + " " + to_string(k) + " " + to_string(rid));
                    freeC[k] = false;
                    remoteReady[k] = now_t + S + table.lookup(1, (double)Lin[rid]);

                } else if (bestType == 1) {
                    int m = (int)qDProc[k].size();
                    string line = "C" + to_string(k) + " D PROC " + to_string(k) + " " + to_string(m);
                    for (int r : qDProc[k]) line += ' ' + to_string(r);
                    lines.push_back(move(line));
                    qDProc[k].clear();
                    freeC[k] = false;
                    remoteReady[k] = now_t + S + table.lookup(4, (double)m);
                }

            } else if (aggressiveThroughput) {
                bool hasResume = (pprocResumeRid[k] != -1);
                bool hasPWork = !qPProc[k].empty() || hasResume;
                bool hasDWork = !qDProc[k].empty();

                double sc_pproc = -1e18, sc_dproc = -1e18;

                if (hasPWork) {
                    int b = hasResume ? pprocResumeRid[k] : qPProc[k].front();
                    sc_pproc = w_c * urg1(b) + w_tp * PREFILL_TP_BONUS;
                }
                if (hasDWork) {
                    int b = qDProc[k].front();
                    sc_dproc = w_c * urg2(b) + POST_BONUS * 0.5 + w_tp * DECODE_TP_BONUS;
                }

                if (!hasPWork && !hasDWork) continue;

                // Unchanged from the confirmed-best doD heuristic, except
                // qPProc[k].empty() is replaced with !hasPWork so a
                // pending split resume counts as "P side has work,"
                // exactly like a fresh candidate would.
                bool doD;
                if (!hasDWork) {
                    doD = false;
                    starvedPProcJustRun[k] = 0;
                } else if (!hasPWork) {
                    doD = true;
                    starvedPProcJustRun[k] = 0;
                } else {
                    bool localDecodeBacklog = (qDPre.size() + qDPost.size()) > 1;
                    if (!localDecodeBacklog && qDProc[k].size() <= 1 && !starvedPProcJustRun[k]) {
                        doD = false;
                        starvedPProcJustRun[k] = 1;
                    } else {
                        doD = true;
                        starvedPProcJustRun[k] = 0;
                    }
                }

                if (doD) {
                    int m = (int)qDProc[k].size();
                    string line = "C" + to_string(k) + " D PROC " + to_string(k) + " " + to_string(m);
                    for (int r : qDProc[k]) line += ' ' + to_string(r);
                    lines.push_back(move(line));
                    qDProc[k].clear();
                    freeC[k] = false;
                    remoteReady[k] = now_t + S + table.lookup(4, (double)m);
                } else if (hasResume) {
                    // CANDIDATE: finish the previously split P_PROC now.
                    // Always dispatches the final piece unconditionally --
                    // no further splitting, no further deferral.
                    int rid = pprocResumeRid[k];
                    int ls = pprocResumePos[k];
                    int le = num_layers;
                    lines.push_back("C" + to_string(k) + " P PROC " + to_string(ls) + " " +
                                    to_string(le) + " " + to_string(k) + " " + to_string(rid));
                    freeC[k] = false;
                    double pieceDur = (double)(le - ls) / (double)num_layers *
                                       table.lookup(1, (double)Lin[rid]);
                    remoteReady[k] = now_t + S + pieceDur;
                    pprocResumeRid[k] = -1;
                } else {
                    int rid = qPProc[k].front();

                    // CANDIDATE: split only when there is real decode work
                    // that would otherwise have to wait out this entire
                    // P_PROC. num_layers >= 2 is required (splitting is
                    // impossible otherwise, per the protocol's own rule).
                    bool shouldSplit = (num_layers >= 2) && hasDWork;

                    if (shouldSplit) {
                        qPProc[k].pop_front();
                        int le = (num_layers + 1) / 2;
                        lines.push_back("C" + to_string(k) + " P PROC 0 " + to_string(le) + " " +
                                        to_string(k) + " " + to_string(rid));
                        freeC[k] = false;
                        double pieceDur = (double)le / (double)num_layers *
                                           table.lookup(1, (double)Lin[rid]);
                        remoteReady[k] = now_t + S + pieceDur;
                        pprocResumeRid[k] = rid;
                        pprocResumePos[k] = le;
                    } else {
                        qPProc[k].pop_front();
                        lines.push_back("C" + to_string(k) + " P PROC 0 " + to_string(num_layers) + " " + to_string(k) + " " + to_string(rid));
                        freeC[k] = false;
                        remoteReady[k] = now_t + S + table.lookup(1, (double)Lin[rid]);
                    }
                }

            } else {
                int bestType = -1;
                double bestPriority = -1e18;
                vector<int> bestIds;

                if (!qPProc[k].empty()) {
                    int rid = qPProc[k].front();
                    double score = w_c * urg1(rid) + w_tp * PREFILL_TP_BONUS;
                    double dur = S + table.lookup(1, (double)Lin[rid]);
                    double pri = score / dur;
                    if (pri > bestPriority) { bestPriority = pri; bestType = 0; bestIds = {rid}; }
                }

                if (!qDProc[k].empty()) {
                    int m = (int)qDProc[k].size();
                    double score = w_c * topKAveUrg2(qDProc[k]) + POST_BONUS * 0.5 + w_tp * DECODE_TP_BONUS;
                    double dur = S + table.lookup(4, (double)m);
                    double pri = score / dur;
                    if (pri > bestPriority) { bestPriority = pri; bestType = 1; }
                }

                if (bestType == 1) {
                    int m = (int)qDProc[k].size();
                    string line = "C" + to_string(k) + " D PROC " + to_string(k) + " " + to_string(m);
                    for (int r : qDProc[k]) line += ' ' + to_string(r);
                    lines.push_back(move(line));
                    qDProc[k].clear();
                    freeC[k] = false;
                    remoteReady[k] = now_t + S + table.lookup(4, (double)m);
                } else if (bestType == 0) {
                    int rid = bestIds[0];
                    qPProc[k].pop_front();

                    lines.push_back("C" + to_string(k) + " P PROC 0 " + to_string(num_layers) + " " + to_string(k) + " " + to_string(rid));
                    freeC[k] = false;
                    remoteReady[k] = now_t + S + table.lookup(1, (double)Lin[rid]);
                }
            }
        }

        cout << lines.size() << '\n';
        for (const string& line : lines) {
            cout << line << '\n';
        }
        cout.flush();
    }

    return 0;
}