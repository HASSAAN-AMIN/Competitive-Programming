/*
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
    In the name of Allah, the Most Gracious, the Most Merciful.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <random>
#include <chrono>
#include <set>


// #include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()

#define YES cout << "YES\n"
#define NO cout << "NO\n"

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << '\n'
#else
#define debug(x)
#endif

const int MOD = 1'000'000'007;
// const int MOD = 998244353;

const int INF = 1'000'000'000; // 1e9
const ll LINF = 4'000'000'000'000'000'000LL; // 4e18

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
void show(const T &arr, ostream &out = cout) {
    for (auto x : arr)
        out << x << ' ';
    out << '\n';
}

template<class T>
bool chmin(T &a, T b) {
    if (b >= a) return false;
    a = b;
    return true;
}

template<class T>
bool chmax(T &a, T b) {
    if (b <= a) return false;
    a = b;
    return true;
}



void solve() {
    
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    int st = -1, cnt = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        if (arr[i] == 0) {
            st = i;
            cnt++;
        }

        mx = max(mx, arr[i]);
    }

    if (cnt != 1) {
        cout << -1 << '\n';
        return;
    }

    vector<vector<int>> lvl(mx + 1);

    for (int i = 0; i < n; i++) {
        lvl[arr[i]].push_back(i);
    }

    vector<int> deg(n, 0);
    vector<pair<int,int>> ans;

    for (int i = 1; i <= mx; i++) {

        if (lvl[i - 1].empty()) {
            cout << -1 << '\n';
            return;
        }

        set<pair<int,int>> s;

        for (int u : lvl[i - 1]) {
            s.insert({deg[u], u});
        }

        for (int u : lvl[i]) {

            if (s.empty()) {
                cout << -1 << '\n';
                return;
            }

            auto [d, v] = *s.begin();
            s.erase(s.begin());

            if (d >= k) {
                cout << -1 << '\n';
                return;
            }

            ans.push_back({u, v});

            deg[u]++;
            deg[v]++;

            s.insert({deg[v], v});
        }
    }

    cout << ans.size() << '\n';

    for (auto [u, v] : ans) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    auto st = chrono::steady_clock::now();
#endif

    int t = 1;
//    cin >> t;

    while (t--) {
        solve();
    }

#ifdef LOCAL
    auto end = chrono::steady_clock::now();
    cerr << "Time: "
         << chrono::duration<double, milli>(end - st).count()
         << " ms\n";
#endif

    return 0;
}