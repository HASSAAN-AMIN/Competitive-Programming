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

    string s;
    string t;
    cin >> s >> t;

    int n = s.size();
    const int INF = 1e9;

    vector<vector<int>> dp(n + 1, vector<int>(2, INF));


    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        
        int x = s[i - 1] - '0'; 
        int y = t[i - 1] - '0'; 

        dp[i][0] = min(dp[i - 1][0] + (x != 0) + (y != 0),   //  even -> even x must 0
                       dp[i - 1][1] + (x != 1) + (y != 0));  //  odd  -> even x must 1

        dp[i][1] = min(dp[i - 1][0] + (x != 1) + (y != 1),   //  even -> odd x must 1
                       dp[i - 1][1] + (x != 0) + (y != 1));  //  odd  -> odd x must 0
    }

    cout << min(dp[n][0], dp[n][1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    auto start = chrono::steady_clock::now();
#endif

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

#ifdef LOCAL
    auto end = chrono::steady_clock::now();
    cerr << "Time: "
         << chrono::duration<double, milli>(end - start).count()
         << " ms\n";
#endif

    return 0;
}