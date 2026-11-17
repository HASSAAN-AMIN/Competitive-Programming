/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const long long MOD = 1000000007;
const int N = 1000000;

vector<long long> fact(N + 1), inv_fact(N + 1);

long long power(long long a, long long b){
    long long res = 1;
    a %= MOD;
    while(b > 0){
        if(b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void build(){
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }
    inv_fact[N] = power(fact[N], MOD - 2);
    for (int i = N; i > 0; i--) {
        inv_fact[i-1] = inv_fact[i] * i % MOD;
    }
}

long long nCr(int n, int r){
    if(r < 0 || r > n)
        return 0;
    return fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    build();

    int t;
    cin >> t;
    while(t--){
        int n, r;
        cin >> n >> r;

        cout << nCr(n, r) << '\n';
    }

    return 0;
}
