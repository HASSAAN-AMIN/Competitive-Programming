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

void first(){
    int n ;
    cin >> n;
    string s;
    cin >> s; 

    bool sus = false ;

    for(char c : s){
        if( c == '1'){
            sus =true;
            break ;
        }
    }


    if(!sus ){
        cout <<  n << '\n'; 
        cout << "1  2" << '\n' ;
        cout << "3  2" << '\n' ;
        cout << "1  3" << '\n' ;

        for (int i = 4 ; i <= n; i++) {
            cout << "1 " << i << '\n'; 
        }

        return;
    }

    // find
    int idx =  -1 ;

    for( int  i = 0 ; i < s.size() ; i++ ){
        if( s[i] == '1'){
            idx = i;
            break; 
        }
    }

    cout << n-1 << '\n' ;

    for (int i = 2; i <= n; i++) {
        if( s[i-2] == '1'){
            cout << "1 " << i << '\n';
        }else{
            cout << idx+2 << ' ' << i << '\n' ; 
        }
    }

}


void dfs( int u , vector<vector<int>>&gr, vector<int> &col , bool &sus , bool c = true){

    if(sus)
        return;
    for( auto v : gr[u]){
        if( col[v] != -1){
            if(col[v] == col[u]){
                sus = true;
                return;
            }
            continue;
        }else{
            col[v] = !c; 
            dfs( v , gr , col , sus , !c) ;
        }
        if(sus)
            return;
    }

}


void second(){
    int n , m; 
    cin >> n >> m;

    vector<vector<int>> gr( n , vector<int>()) ;
    
    for (int i = 0; i < m; i++) {
        int u , v;
        cin >> u >> v ;
        u--;
        v--;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    bool sus = false;
    

    vector<int>col(n , -1) ;    
  //  vector<bool> vis(n , false) ;
    col[0] = 0 ;    
  //   vis[0] = true;
    dfs(0 , gr , col , sus , false) ;


    if(sus){
        for (int i = 0; i < n-1; i++) {
            cout << 0 ;
        }
        cout << '\n';
    }else{
        for (int i = 1; i < n; i++) {
            cout << col[i] ; 
        }
        cout << '\n' ; 
    }

    // for (int i = 0; i < n; i++) {
        
    // }

}


void solve() {
    
    
    string s;
    cin >> s;
    int t = 1;
    cin >> t;

    

    if( s == "first")   {
        while (t--) {
        first();
        }
    }
    else{
        while (t--) {
        second();
        }
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