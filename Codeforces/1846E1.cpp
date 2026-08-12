/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <cmath>
#include <unordered_set>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long big = 1e18;
    unordered_set<long long> ss;
    for( long long k = 2 ; k <= 1e6 ;k++){
        
        long long st = 1 + k + k*k ;
        long long now = k*k*k;

        ss.insert(st);

        while( st < big){
            if (now > big - st)
                break;
            st += now ;
            ss.insert(st);
            if (now > big / k)
                break;
            now *= k;
        }
    }
    

    int t;
    cin >> t;
    while(t--){
        
        long long x;
        cin >> x ;

        // i am just gonna try funcitonal equations where else i am supppposed to use that olympiad math 
        // k given
        // f(0) = 1 
        // f(1) = k  +1  // k out 1 insdie
        // f(2) -> we need that
        // f(2) = k*k +1 + k
        //      => 1 + k + k*k +  ( go on k*k*k  .. )
        //   G_sum =  a1 * ((1-r^n))/(1-r) 
        // for finite
        // so so sososssos
        // a1 = 1  dissapera boom
        // g sum = ( k^(n+1) - 1)/(k- 1 )        
        // wait it is that simple ? 
        //  just binary search over n  ?
        // wait j  is unknows
        // n+1 upper bound is log base 2 1e18 ? floor 59?
        // n+1 can be like from  2 - 59 
        // n bound 1 58 ? for k 2 right
        // for what k ?
        // k can be  like  1 + k + k*k
        // and for bigger  1+k+k*k + k*k*k
        // for bigger it just gonna be like  cbrt 1 e18
        // 1 e6 ?
        // k 1 e6

        // jus check till 1e6
        // coz thats what time allows
        // but but but for small case this can be 1e9
        // so we just solve that quadratic ?


        bool sus  = false;

        // k(k +1 ) = x -1
        long long a = sqrt(x-1) ;

        if (a > 1 && a * (a + 1) == x - 1) {
            sus = true;
        }
        
        if(!sus && ss.count(x)){
            sus = true;
        

            // check all
            // nigga precompute this

            // for( int k = 2 ; k <= 1e3 ;k++){
            //     long long st = 1 + k + k*k ;
                
            //     long long now = k*k*k;
            //     while( st < x){
            //         if (now > x - st)
            //             break;
            //         st += now ;
            //         if (now > x / k)
            //             break;
            //         now *= k;
            //     }
            //     if( st == x){
            //         sus = true;
            //         break;
            //     }
            // }
        }

        if( sus )
            cout << "YES" << '\n';
        else    
            cout << "NO" << '\n' ;

        
    }

    return 0;
}