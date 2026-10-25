/*
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
    In the name of Allah, the Most Gracious, the Most Merciful.
*/

// Codeforces Profile : https://codeforces.com/profile/hexshu
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
    

    ll n , k  ;
    cin >>  n  >> k ; 
    

    vector<string> arr(k) ,brr(k);

    for (int i = 0; i < n; i++) {
        ll u , v ;
        cin >> u >> v;

        for (int j = 0; j < k; j++) {
            if( u &(1ll<<j) )
                arr[j] += '1';
            else
                arr[j] += '0' ;

            if( v &(1ll<<j) )
                brr[j] += '1';
            else
                brr[j] += '0' ;
        }   
    }

    vector<int> crr(k); 
    vector<bool> vis(k) ;
    bool sus = false;
    for (int i = 0; i < k; i++) {
        sus = false;
        for (int j = 0; j < k; j++) {
            if(arr[i] == brr[j]  && !vis[j]){
                crr[i] = j;
                vis[j] = true;
                sus = true;
                break;
            }
        }
        if(!sus){
            cout << -1 << '\n';
            return ;
        }
    }

    for (int i = 0; i < k; i++) {
        cout << crr[i] << ' '; 
    }

    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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