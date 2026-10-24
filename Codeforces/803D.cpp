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



bool foo( int u , int k ,  vector<int>& arr ){

    int now = 0 ;
    int cnt = 1 ;

    for( auto v : arr){

        if( now + v > u){
            cnt++;
            now = v ;
        }else{
            now += v;
        }
    }
    return cnt <= k ;

}




void solve() {
    int n;
    cin >> n;

    cin.ignore();
    string s;
    getline(cin , s) ;

    int cnt = 0 ;
    vector<int> arr; 
    for( char c : s){
        cnt++;
        if( c == ' ' || c == '-'){
            arr.pb(cnt);
            cnt = 0 ;
        }
    }
    arr.pb(cnt);

    // min width  = min size
    // max width = total len

    // min --> max
    // height dec

    // height given
    // needed minimal width


    // as height decreases
    // FFFFFTTTTTFFFFF
    // for some height we got answers
    // needed 

    // minimal width
    // needed first true
    // so BS for first true
    // to set right to last true
    

    // sa-l fun
    // sa-
    // l.
    // fun
    // 3 2 3

    // height is given

    // construct
    // height ->
    // small   mediumm   good   large
    // widht ->
    // large    good    medium   small

    // we have fix height
    //   we need last T actually

    //for low

    // bruhh its actuall 
    // FFFFTTTTTTTTTT
    // bs on width not height
    // also height is no more than k 

    
   //  sort(all(arr));
    int r = s.size();
    int l = *max_element( all(arr)) ;

    while( l < r){
        int m = l + (r-l)/2 ;

        if( foo(m , n,  arr)){
            r = m;
        }else{
            l = m+1; 
        }
    }
    cout<< l << '\n'; 


    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LOCAL
    auto start = chrono::steady_clock::now();
#endif

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

#ifdef LOCAL
    auto end = chrono::steady_clock::now();
    cerr << "Time: "<< chrono::duration<double, milli>(end - start).count() << " ms\n";
#endif

    return 0;
}