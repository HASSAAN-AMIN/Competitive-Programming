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
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        int xr  = 0  ;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            xr = xr ^ arr[i] ;
        }

        if( xr == 0){
            cout << "YES" << '\n' ;
        }else{
            // else wise 
            // the total xor have to come
            // like more that 2 times
            int cnt = 0 ;
            int now = 0; 
            for (int i = 0; i < n; i++) {
                now = now ^ arr[i] ;
                
                if( now == xr){
                    cnt++;
                    now = 0 ; 
                }

            }

            if( cnt > 1){
                cout << "YES" << '\n';
            }else{
                cout << "NO" << '\n'; 
            }
        }

        
    }

    return 0;
}