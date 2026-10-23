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

int ask( int a , int b){
    cout << '?' << ' ' << a << ' ' << b << '\n' ;
    int x;
    cin >> x;
    return x;
}

void solve() {

    int a = 0;
    int b = 0;

    bool big = ask( 0 ,0 ) ;
    
    for (int i = 29 ; i >=  0 ; i--) {

        int p = ask(  a^(1<<i)  ,  b);
        int q = ask(  a ,  b^(1<<i));


        if( p != q){
            
            if( p == -1){
                a |= (1 << i);
                b |= (1 << i); 
            }

        }else{
            // 0 1
            // 1 0 
            if(big){
                a |= (1 << i);
            }else{
                b |= (1 << i);
            }
            
            if( p ==1 )
                big = true;
            else
                big= false;
        }
    }
    cout << '!' << ' ' << a << ' ' << b << '\n'; 

    
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

#ifdef LOCAL
    auto start = chrono::steady_clock::now();
#endif

    int t = 1;
   //  cin >> t;

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