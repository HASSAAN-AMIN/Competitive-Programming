/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;

vector<int> sieve(int n) {
    
    vector<int> primes;
    if (n < 2) 
        return primes;
    
    primes.push_back(2);
    if (n == 2) 
        return primes;

    int size = (n - 1) / 2;
    vector<bool> iss(size, true);

    int l = (sqrt(n) - 3) / 2;
    
    for (int i = 0; i <= l; ++i) {
        if (iss[i]) {
            int p = 2 * i + 3;
            int s = (p * p - 3) / 2;
            for (int j = s; j < size; j += p) {
                iss[j] = false;
            }
        }
    }

    for (int i = 0; i < size; ++i) {
        if (iss[i]) {
            primes.push_back(2 * i + 3);
        }
    }

    return primes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> primes = sieve(1e5);


    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k ;
        cin >> k;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        //  a.b =  x ^ k
        //  x ^ k = (x)(x)...(x)
        // so all the prime factors are
        //  0 mod k ?

        // so umm
        // x can be different for  like any pair
        // we cant also check all pairs
        // even if O(1) per check
        
        // process every number
        // find prime divisors but mod k
        // if its 0 mod k we wont need it
        // why ? coz its mr perfect
        // and have a like map or smth like storign
        // i mean if it have 3^2 
        // we would check from back that is there any guy
        // who have that specific 3^(k-2) or not like we need that
        // and cnt of that many  +=  into ans
        // but but but we dont have one prime divisor
        // we can have many
        // but how do we cmp that
        // a map  ?  what key and what val ?
        // val ofc cnt of that many gonna be int
        // map <vector<int> , int > type shi ?
        // actually map < vector<pair<int , int>>  , int> type shi?


        // unordered_map< vector<pair<int , int> > , int>  mapy;
        // nvm unorderd map doestn support hash for this for some stupid reasons which idk
        // but map do
        // but the log n operations could be expensive as hell as far i think 
        // idk just do this implementation 


        map < vector< pair< int, int >>  , int > mapy ;

        long long ans = 0 ;

        // so i generate prime numbers now  ?
        for (int i = 0; i < n; i++) {
            vector<pair <int ,int>> in;
            for (int j = 0; j < primes.size(); j++) {
                if( primes[j] > arr[i])
                    break;
                int cnt  = 0;
                while( arr[i]%primes[j] == 0){
                    arr[i]/= primes[j]; 
                    cnt++;
                }
                if(cnt &&  cnt%k != 0){
                    pair<int ,int > p = {primes[j] , cnt%k} ;
                    in.push_back(p);
                }
            }
            // what we require?
            vector<pair<int , int>> req( in.size());
            for (int i = 0; i < in.size(); i++) {
                req[i].first = in[i].first;
                req[i].second = k - in[i].second; 
            }
            ans += mapy[req];
            mapy[in]++;
        }

        cout << ans << '\n' ;

    }

    return 0;
}