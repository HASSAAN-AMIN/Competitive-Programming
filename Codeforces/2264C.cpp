/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD  = 998244353; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    vector<long long> fact(200001);

    fact[0] = 1;
    for(int i = 1; i < 200001; i++)
        fact[i] = fact[i-1] * i % MOD;

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<long long> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // always one root
        // largest fixed
        // 2nd largest also fixed
        
        // all of remaining can be paired with the root
        // add those difference ?
        // no no no not like that


        // a_p - a_son
        // son will also be parent sm day
        // s_son - a_grandson
        // a can be more times parent then son or vice ?
        // a will always be parent and also son
        // might not have son sometimes
        // means might not be parent
        // but is always a son
        // always a son

        // for eache elemnet how many times it ca

        // for each number
        // how many parents it can have  :skull
        // numbers greater than it
        
        // and for next the numbers greater than it
        // so factorial of numbers greater then me

        // since what matters is the difference with that specific son parent
        // we take k-1 fact and then multiply by k  ?
        // thats k !
        // but we gonna
        // sum that ? 
        // sum with parent son differecne
        // writeshi

        vector<long long> suff(n+1);

        suff[n] = 1;

        for(int i = n-1; i >= 1; i--)
            suff[i] = suff[i+1] * i % MOD;

        
        sort( arr.begin()  , arr.end( )) ;
        long long ans = 0 ;
        long long sum = arr[n-1];




        for(int i = n-2; i >= 0; i--) {


            // if(n-i-1 == 0)
            //     continue;

            ans += (sum - arr[i] * (n-i-1)) % MOD * (fact[n-i-2] * suff[n-i] % MOD) % MOD;
            ans %= MOD;

            sum += arr[i];
        }
        ans += MOD ;
        cout << ans%MOD << '\n' ;
    }

    return 0;
}