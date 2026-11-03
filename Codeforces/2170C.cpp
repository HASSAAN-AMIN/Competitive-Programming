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
    int n;
    cin >> n;
    ll k;
    cin >> k;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int u ;
        cin >> u;
        if( u <= k)
            arr.pb(u); 
    }
    vector<int> brr(n);
    for (int i = 0; i < n; i++) {
        int u ;
        cin >> u;
        if( u <= k - 2)
            brr.pb(u); 
    }

    
    cout << min ( sz(arr) , sz(brr))  << '\n'; 
    // x/y
    // y < x < k
    // first  arr[i] > k
    // x/y == arr[i] ;
    // x == y * arr[i];
    // x = y* arr[i] + 1 ;


    // x/y < k   &&   arr[i] > x/y


    // brr[i]  = x mod y
    // x = q*y + brr[i]
    // y * arr[i] = q *y + brr[i]

    // y( arr[i]  - q ) =  brr[i]

    //   y = brr[i] / ( arr[i] - q) - { 1 / ( arr[i] - q) )}
    // 
    

    // r 7
    // k 10

    // rem -> 7

    //  15/8 
    // 2*r +1 / r+1

    // q*y + r = x
    // arr[i]*y + brr[i] = x
    // 




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