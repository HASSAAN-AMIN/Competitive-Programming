/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


const int MOD = 1e9+ 7 ;


long long ans( int a , int b , int MOD){
    long long ans = 1 ;

    while(b){
        if(b&1){
            ans = (ans * a)%MOD;
        }
        a = (1ll*a*a)%MOD ;
        b >>= 1 ;
    }
    ans += MOD ; 
    return ans%MOD ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int a , b ,c  ;
        cin >> a >> b >> c; 

        cout << ans( a , ans( b , c , MOD -1 ) , MOD)  << '\n' ;


        
    }

    return 0;
}