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


bool null( int i , vector<int> &arr){
    return i >= sz(arr) || arr[i] <= 0 ;
}


bool help( int i , vector<int> &arr , ll lo =  -1e9 , ll hi = 1e9){
    if( null(i , arr))
        return true;
    
    if( arr[i] <= lo || arr[i] >= hi)
        return false;
    
    return help(2*i+1 ,  arr, lo , arr[i])  &&  help(2*i+2 ,  arr, arr[i] , hi)  ; 
}

bool check( int i , vector<int> &arr){

    if( null(i , arr))
        return false;

    return help( i , arr ); 

}

ll foo( int i , vector<int> &arr){
    if( null( i  , arr))
        return 0 ;
    return arr[i] + foo(2*i+1 , arr) + foo(2*i+2 , arr) ;
}


void solve() {
   //  cin.ignore() ;
    int x;
    vector<int> arr;
    while( cin >> x){
        arr.push_back(x);
    }

    int n = arr.size() ;

    if( n ==  0){
        cout <<  0 << '\n';
        return ;
    }

    ll ans =0 ;

    for (int i = 0; i < n; i++) {

        if(check(i , arr)){
            // if is a binary tree
            chmax(ans, foo(i , arr)); 
        }
    }

    cout << ans << '\n';

    
    
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

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