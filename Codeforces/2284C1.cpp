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


vector<int> pn(2e5 + 1, 2e5 + 1);


vector<bool> sieve(int n) {
    vector<bool> isp(n + 1, true);   
    isp[0] = false;
    isp[1] = false;      

    for (int i = 2; i*i <= n; i++) {
        if (isp[i]) {
            for (int j = i * i; j <= n; j += i) {
                isp[j] = false;      
            }
        }
    }
    return isp;
}

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = pn[arr[i]];
    }

    show(arr);
    
}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    auto start = chrono::steady_clock::now();
#endif

    vector<bool> isp = sieve(2e5);
    for (int i = 2e5; i >= 0; i--) {
        if(isp[i])
            pn[i] = i;
        else
            pn[i] = pn[i+1] ;
    }
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