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
    
    ll h ,c, t;
    cin >> h >> c >> t;

    
    if( h + c  - 2*t < 0 ){

        int a = t-h;
        int b = h+c-2*t; 
        int k = a/b ; 
        if (abs(1LL*((k+1)*h + k*c) - 1LL*t*(2*k+1)) * (2*k+3) > abs(1LL*((k+2)*h + (k+1)*c) - 1LL*t*(2*k+3)) * (2*k+1))
            k++;
        cout <<  2*k+1 << '\n' ;
    }else{
        cout << 2 << '\n';
    }



}

// Thursday  =>   HCI ( 11:40 - 12:40 )

// Friday    =>   TBW (  9:00 - 10:00 )
//                 CA (  2:30 -  3:30 )

// Saturday  =>   Algo(  2:30 -  3:30 )

// Sunday 

// Monday    =>   CNET(  2:30 -  3:30 )
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