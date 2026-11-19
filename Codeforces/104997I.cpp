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
    int n, m;
    cin >> n >> m;

    vector<ll> pre(m + 1, 0);
    vector<ll> suf(m + 1, 0);

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        pre[u]++;
        suf[v]++;
    }

    vector<ll> str(2 * m + 1, 0);
    vector<ll>  end(2 * m + 1, 0);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            str[i + j] += pre[i] * pre[j];
            end[i + j] += suf[i] * suf[j];
        }
    }

    for (int i = 1; i <= 2 * m; i++) {
        str[i] += str[i - 1];
        end[i] += end[i - 1];
    }

    cout <<  str[0] << '\n' ;
    for (int k = 1; k <= 2 * m; k++) {
        cout << str[k] - end[k - 1] << '\n';
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    auto str = chrono::steady_clock::now();
#endif

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

#ifdef LOCAL
    auto end = chrono::steady_clock::now();
    cerr << "Time: "
         << chrono::duration<double, milli>(end - str).count()
         << " ms\n";
#endif

    return 0;
}