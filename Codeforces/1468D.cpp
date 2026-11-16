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


bool foo(int k, vector<int>& arr, int a, int b, int n) {
    if (k == 0) return true;

    ll dist = abs(a - b);
    ll T = (a < b) ? b - 1 : n - b;   
    
    if (k > dist - 1) 
        return false;

    for (int i = 0; i < k; i++) {
        if (1LL * (i + 1) + arr[k - 1 - i] > T) 
            return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    int m, a,b ;
    cin >> m >> a >> b; 

    vector<int> arr(m);

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    sort( all(arr)) ;


    int lo =  0 ;
    int hi = m;

    //// TTTTTTTTTFFFFFF


    while(lo  < hi ){
        int m  = lo +(hi-lo +1)/2 ; 

        if( foo( m , arr, a , b , n )){
            lo = m ;
        }else{
            hi = m- 1 ;
        }
    }

    cout << lo << '\n';
    
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