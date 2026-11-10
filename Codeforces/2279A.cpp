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

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0 ;

    
    for (int i = 0; i < n-1; i++) {
        ans = max( ans , abs(arr[i] - arr[i+1])); 
    }

    int cnt = 0 ;
    int idx1 = -1 ;
    int idx2 = -1 ;
    for (int i = 0; i < n-1; i++) {
        if(abs(arr[i] - arr[i+1]) ==  ans){
            cnt++;
            if( cnt == 1)
                idx1 = i;
            else 
                idx2 = i; 
        } 
    }

    if( cnt > 2){
        cout << ans << '\n'; 
        return;
    }else if( cnt == 2){

        reverse(arr.begin() + idx1 + 1, arr.begin() + idx2 + 1);

        int ans2 = 0 ;

        for (int i = idx1+1; i <= idx2; i++) {
            arr[i] = 2*arr[i]; 
        }
        
        for (int i = 0; i < n-1; i++) {
            ans2 = max( ans2 , abs(arr[i] - arr[i+1])); 
        }

        cout << min( ans , ans2) << '\n' ;
        return ;
    }

    // main case 


    int idx = idx1;

    
    vector<int> gap(n - 1);
    for (int i = 0; i < n - 1; i++){
        gap[i] = abs(arr[i] - arr[i + 1]);
    }

    
    vector<int> pre(n, 0);
    for (int i = 1; i < n; i++) {
        pre[i] = max(pre[i - 1], gap[i - 1]);
    }

    vector<int> suf(n + 1, 0);
    for (int i = n - 2; i >= 0; i--){
        suf[i] = max(suf[i + 1], gap[i]);
    }


    int b = ans;  
    
    auto check = [&](int l, int r, int in) {
        int res = 2 * in;                                  // inside, doubled
        res = max(res, suf[r + 1]);                        // right of piece
        if (l >= 1) {
            res = max(res, pre[l - 1]);                    // left of piece
            res = max(res, abs(arr[l - 1] - 2 * arr[r]));     // left edge
        }
        if (r + 1 < n) {
            res = max(res, abs(2 * arr[l] - arr[r + 1]));     // right edge
        }
        return res;
    };

    

    int in = 0;
    for (int i = idx + 1; i < n; i++) {
        if (i > idx + 1) 
            in = max(in, gap[i - 1]);
        b = min(b, check(idx + 1, i, in));
    }

    
    in = 0;
    for (int l = idx; l >= 0; l--) {
        if (l < idx) 
            in = max(in, gap[l]);
        b = min(b, check(l, idx, in));
    }

    cout << b << '\n';

    
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