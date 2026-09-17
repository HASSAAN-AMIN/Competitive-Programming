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

    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        int cnt = 0 ;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if( arr[i] == 1)
                cnt++;
        }

        // make all 1
        // if any two replace with gcd
        // their gcd remains same
        // so we need two coprime and then when they meet
        // they will make a 1
        // that 1 will make everyone one
        // if already one ?
        // also if no any coprime its -1 ;



        if( cnt ){
            cout << n - cnt  << '\n';
        }else{
            int full = 0 ;

            for( auto u : arr){
                full = __gcd( full , u); 
                if(full == 1)
                    break;
            }   

            int len  = 2000 ;
            for (int i = 0; i < n; i++) {
                int gg = arr[i] ;
                for (int j = i+1; j < n; j++) {
                    gg = __gcd( gg , arr[j]);
                    if( gg == 1){
                        len = min( len , j- i  );
                        break; 
                    }
                }
            }
            
            if( full != 1 )
                cout << -1 << '\n';
            else    
                cout << n - 1 +  len << '\n' ;
            
            
        }



    }

    return 0;
}