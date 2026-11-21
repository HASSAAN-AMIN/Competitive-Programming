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


bool check(ll x, int n, vector<ll>& pre, vector<ll>& suf, ll sum) {
    

    int l = 2;
    int r = n - 1;

    while (l < n && suf[l] > x) 
        l++;
    while (r >= 2 && pre[r] > x) 
        r--;

    if (l > r)  
        return false;

    return pre[r] - pre[l - 1] >= sum - x;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<ll> pre(n + 1, 0);
    vector<ll> suf(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }

    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + arr[i];
    }

    ll sum = pre[n];

    ll l = 0;
    ll r = sum;

    while (l < r) {
        ll mid = l + (r - l) / 2;

        if (check(mid, n, pre, suf, sum)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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