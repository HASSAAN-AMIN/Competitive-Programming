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

#include <unordered_map>

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

//const int MOD = 1'000'000'007;
const int MOD = 998244353;

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



ll pow( int a , int b){
    ll res=  1 ;
    
    b %= MOD ; 
    while( b)  {
        if( b&1){
            res = (res*a)%MOD;
        }
        a = (1ll*a*a)%MOD;
    
        b >>= 1 ;
    }
    return res; 
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int> > arr(n);


    unordered_map<int , int> mp ;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = vector<int>(x);
        for (int j = 0; j < x; j++) {
            cin >> arr[i][j] ; 
            mp[arr[i][j]]++ ;
        }
    }
    
    ll ans  = 0 ;

    for (int i = 0; i < n; i++) {
        ll s= 0 ;
        int k =sz(arr[i]);
        for( auto u:  arr[i]){
            s+= mp[u];
            s%= MOD;
        }
        ans = (ans + s * pow(k, MOD - 2)) % MOD;
    }

    ll inv = pow(n, MOD - 2);   
    ans = ans * inv % MOD * inv% MOD;  

    cout << ans << '\n' ;


    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    auto start = chrono::steady_clock::now();
#endif

    int t = 1;
   // cin >> t;

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