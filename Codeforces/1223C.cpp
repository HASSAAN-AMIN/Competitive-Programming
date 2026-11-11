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
long long lcm( int a , int b){
    return (1ll*a*b)/__gcd(a, b); 
}

bool foo( int u , int x ,int a ,int y , int b , ll k ,  vector<int> &arr){

    if(  y > x ){
        swap( x ,y );
        swap( a, b );
    }

    int cnt1  = u/a;
    int cnt2  = u/b;
    // in both

    int cnt3  = u/lcm(a,b) ;

    cnt1 -= cnt3;
    cnt2 -= cnt3; 

    if( cnt3 == 0){
        //int i  =  0 ;
        ll ans  = 0 ;
        for (int i = 0; i < cnt1; i++) {
            ans += (x*arr[i])/100 ;
        }
        for (int i = cnt1 ; i < cnt1+ cnt2; i++) {
            ans += (y*arr[i])/100 ; 
        }
        return ans >= k ; 
    }

    ll ans = 0 ;

    for (int i = 0; i < cnt3; i++) {
        ans += (1ll*(x+y)*arr[i])/100 ;
    }
    for (int i = cnt3; i < cnt3+cnt1; i++) {
        ans += (1ll*x*arr[i])/100 ;
    }

    for (int i = cnt3+cnt1; i < cnt3+cnt1+ cnt2; i++) {
        ans += (1ll*y*arr[i])/100 ;
    }

    return ans  >= k   ;
}



void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    // p
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x , a;
    int y , b;
    cin >> x >> a ;
    cin >> y >> b ;
    ll k ;
    cin >> k ;

    //   FFFFFFFFFFFTTTTTTTTTTTTTTTTT


    sort(all(arr) , greater<int>() ) ;

    if (!foo(n, x, a, y, b, k, arr)) {
        cout << -1 << '\n';
        return;
    }
    int lo = 0 ;
    int hi = n ;
  //  int ans= -1 ;
    while( lo < hi){
        int m = lo + ( hi - lo)/2 ;

        if( foo( m , x ,a , y ,b , k ,  arr) ){
            hi = m;
          //  ans = m ;
        }else{
            lo = m+ 1;
        }
    } 

    cout << lo << '\n' ;

    
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