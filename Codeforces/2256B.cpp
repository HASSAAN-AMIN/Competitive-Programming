/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int MOD = 998244353;
const int maxx = 1e6;  

long long fact[maxx], inv[maxx];

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) 
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

long long C(int n, int k) {
    if (k < 0 || k > n) 
        return 0;
    return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    fact[0] = 1;
    for (int i = 1; i < maxx; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    inv[maxx - 1] = modpow(fact[maxx - 1], MOD - 2);
    for (int i = maxx - 1; i >= 1; i--) {
        inv[i - 1] = inv[i] * i % MOD;
    }

    
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;


        int z = 0, o = 0;
        for (char c : s) {
            if (c == '0')  
                z++;
            else 
                o++;
        }
        

        int zz = 0, oo = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0 || s[i] != s[i - 1]) {
                if (s[i] == '0') 
                    zz++;
                else 
                    oo++;
            }
        }
        // cout << " zz :  " << zz << '\n';
        // cout << " oo :  " << oo << '\n';  
        long long ans = 1;
        if (zz > 0) {
            ans = ans * C(z - 1, zz - 1) % MOD;
        }
        if (oo > 0) {
            ans = ans * C(o - 1, oo - 1) % MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}