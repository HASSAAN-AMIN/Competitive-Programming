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

#include <queue>

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
    
    int n , m ;
    cin >> n >> m ;

    vector<vector<int>> arr( n) ;

    for (int i = 0; i < n-1; i++) {
        int u  , v ;
        cin >> u >> v ;
        u--; 
        v--;
        arr[u].push_back(v); 
        arr[v].push_back(u); 
    }

    vector<ll> dis( n , -1e9) ; 

    queue<int> q;
    q.push(n-1);
    
    dis[n-1] = 0; 
    while(!q.empty()){
        
        int u = q.front();
        q.pop(); 

        if(u == 0){
            continue; // dont go there bad boy
        }

        for( auto v : arr[u]){
            if(dis[v] < 0){
                dis[v] = dis[u] +1 ;
                q.push(v); 
            }
        }
    }

    ll ans = dis[0]; 

    while(m--){
        int u ;
        cin >> u; 
        u--;
        ans = max( ans , dis[u] + 1) ; 
    }
    cout << ans << '\n'; 

        
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