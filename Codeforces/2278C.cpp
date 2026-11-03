/*
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
    In the name of Allah, the Most Gracious, the Most Merciful.
*/

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility>
// #include <random>
// #include <chrono>

#include <bits/stdc++.h>

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
    int n;
    cin >> n;

    vector<int> arr(n);
    ll sum =  0;
    int cnt = 0 ;
    // int a  = 0 ;
    // int b = 0 ;

    bool sus = false;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // int x ;
        // cin >>x; 
        // if( x != 1){
        //     a += x-1;
        //     b++;
        // }else{

        // }
        if( arr[i] == 1)
            cnt++; 

        
        if (i > 0 && i < n - 1 && arr[i] > 1)
            sus = true;
    }
    sum = accumulate( all(arr) , 0ll) ;


    if (cnt == n) {
        cout << -1 << '\n';
    } else {

        // int i = 0;
        // while(i < n && arr[i] == 1 ){
        //     sum--;
        //     i++;
        // }
        // i = n-1 ;
        // while(i >= 0 && arr[i] == 1 ){
        //     sum--;
        //     i--; 
        // }
        // // if( arr[0] != 1  && arr[n-1] != 1 && cnt > 0 ){
        // //     sum--;
        // // }
        // if( cnt ==  0 )
        //     sum--; 
        // cout << sum   << '\n' ;
        if (sus)
            sum--;
        else
            sum = sum - n + 1;

        cout << sum << '\n';
    }

    
    
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
