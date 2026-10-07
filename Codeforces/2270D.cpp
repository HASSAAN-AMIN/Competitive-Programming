/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <set>

using namespace std;



long long fun( long long  u , long long a ,long long b ,long long c){

    long long v = a  + b+ c  ;


    if( v >= u)
        return 0; 

    if( a > b || b  > c  || a > c){
        return u -v ;
    }

    if( a== c)
        return  2e18 ;
        


    return min ( u + b - 3*a - c + 2  , u + c - a -3*b + 2) ; 

}


bool check(   long long  u , vector< long long > & arr , vector< long long > & brr , vector< long long > & crr , long long k){

    long long cnt = 0  ;
    for (int i = 0; i < arr.size(); i++) {
        
        long long req =  fun( u , arr[i] , brr[i] , crr[i] ); 

        if( req == 2e18 )
            return false; 
        if( req  + cnt  > k )
            return false;
        
        cnt += req; 
    }
    return cnt <=  k  ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        long long k ;
        cin >>k ;
        
        vector<long long> arr(n);
        vector<long long> brr(n);
        vector<long long> crr(n);

        long long lo = 1e18  ;
        long long hi = -1e18  ; 

        for (int i = 0; i < n; i++) {
            
            cin >> arr[i] >> brr[i] >> crr[i] ;
            
            lo  = min( lo  , arr[i]  + brr[i] + crr[i]) ;
            hi  = max( hi  , arr[i]  + brr[i] + crr[i]) ;

        }

        long long l = lo;
        long long h = hi  + k  ;

        long long is = lo ; 
        while( l <=  h){
            long long mid = l + (h-l)/2  ;
            // TTTTTTTFFFFF
            // find last T
            if( check( mid , arr , brr, crr  , k   )){
                is = mid ; 
                l = mid +1;
            }else{
                h = mid -1; 
            }

        }

        cout <<  is << '\n' ;


        
    }

    return 0;
}