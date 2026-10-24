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

bool foo( int m , int k ,unordered_map<int , int>& mp){

    int cnt = 0  ; 
    for(auto u : mp){
        cnt += u.second/m; 
    }
    return cnt >= k  ;
    
}


void solve() {
    int n;
    cin >> n;
    int k= 0 ;
    cin >> k; 

    vector<int> arr(n);

    unordered_map<int ,int> mp;
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++; 
    }
    
    
    // find cuts
    int l = 1 ;
    int r = n;

    // TTTTTTFFFFFF
    while( l < r){
        int m =  l + (r-l+1 )/2 ;

        if( foo( m , k ,   mp)){
            l = m;
        }else{
            r = m-1 ; 
        }
    }

    
    // construct
    int cnt = 0;

    for (auto v : mp) {
        int x = v.second / l;

        while (x-- && cnt < k) {
            cout << v.first << ' ';
            cnt++;
        }

        if (cnt == k) 
            break;
    }
    cout << '\n';

    

    
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