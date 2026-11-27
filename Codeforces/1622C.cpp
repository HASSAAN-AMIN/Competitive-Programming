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


bool foo( ll u , vector<ll> arr , ll k ){


    if( u > arr.size() -1){

        arr[sz(arr)-1] -=  u - sz(arr) +  1 ;

        for (int i = 0; i < sz(arr)-1; i++) {
            arr[i] = arr[sz(arr)-1]  ;
        }
    }else{
        int sm = arr[sz(arr)-1] ;

        if( arr[u-1] == sm){
            u--;
            arr[sz(arr)-1]--;
        }
        for (int i = 0; i < u; i++) {
            arr[i] = arr[sz(arr)-1];
        }
    }

    ll sum = accumulate( all(arr) , 0ll);

    return sum <= k;

}


void solve() {
    int n;
    cin >> n;

    ll k ;
    cin >> k ;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // ll lo = 0  ;
    // ll hi = *min_element(all(arr)) + n ; 

    // //  FFFFFFFFFFFTTTTTTTTT
    // sort( arr.begin() ,arr.end() , greater<int>()) ;

    // while( lo < hi){
    //     ll mid = lo + ( hi-lo)/2 ;

    //     if( foo( mid ,arr  ,k ))
    //         hi = mid;
    //     else
    //         lo = mid+1 ;

    // }

    // cout << lo << '\n'; 

    sort(all(arr));

    vector<ll> pre(n + 1, 0);
    
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + arr[i];
    }

    ll ans = LINF;

    for (int x = 0; x < n; x++) {

        ll sum = pre[n - x] + (ll)x * arr[0];

        ll d = 0;
        if (sum > k) {
            // ceil((sum-k)/(x+1))
            d = (sum - k + x) / (x + 1); 
        }

        chmin(ans, x + d);
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