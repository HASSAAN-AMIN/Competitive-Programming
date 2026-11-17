/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 1000000;

vector<bool> is_prime(N + 1, true);
vector<int> spf(N + 1, 0);
vector<int> primes;

void sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if(is_prime[i]){
            primes.push_back(i);
            spf[i] = i;
            for (long long j = 1LL * i * i; j <= N; j += i) {
                if(is_prime[j]){
                    is_prime[j] = false;
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> factors;
        while(n > 1){
            factors.push_back(spf[n]);
            n /= spf[n];
        }

        for(int x : factors)
            cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
