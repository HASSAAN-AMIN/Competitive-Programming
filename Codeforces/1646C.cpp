/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> fact(15) ;
    fact[0] = 1 ;
    for (long long i = 1; i < 15; i++) {
        fact[i] = fact[i-1]*i*1ll ;
    }

    int t = 1;
    cin >> t;
    while(t--){
        long long n ;
        cin >> n; 


        int ans = __builtin_popcountll(n); 
        for (int b = 0; b < (1 << 15); b++) {

            long long sum= 0  ;
            int cnt= 0; 
            for (int i = 3; i < 15 ; i++) {
                if( (1<<i) & b ){
                    sum += fact[i] ;
                    cnt++ ;
                }
            } 

            if( sum > n)
                continue;
            
            ans = min(ans, cnt + __builtin_popcountll(n - sum));
        }

        cout << ans << '\n' ;
        
        
    }


    return 0;
}