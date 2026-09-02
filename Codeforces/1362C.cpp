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

    int t;
    cin >> t;
    while(t--){
        
        long long n;
        cin >> n ;

        //  0 0 0 0
        //  0 0 0 1
        //  0 0 1 0
        //  0 0 1 1
        //  0 1 0 0
        //  0 1 0 1
        long long ans  = 0 ;
        for (int i =  63 ;  i >= 0; i--) {
            if ( n & (1ll << i )){
                ans += (1ll<<(i+1)) -1 ;
                
            }
        }
        cout << ans << '\n' ;
        

        
    }

    return 0;
}