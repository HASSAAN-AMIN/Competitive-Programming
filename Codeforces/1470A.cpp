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
        
        int n  , m ; 
        cin >> n >> m ; 

        vector<int> arr( n );
        for (int i = 0; i < n; i++) {
            cin >> arr[i] ;
        }

        vector<int> brr( m) ;
        for (int i = 0; i < m; i++) {
            cin >> brr[i] ;
        }

        sort( arr.begin() , arr.end() );


        long long ans = 0;
        int idx = 0 ;

        for (int i = n-1 ; i >= 0 ; i--) {

            if( idx <= arr[i] -1 ){
                ans += brr[idx];
                idx++;
            }else{
                ans += brr[ arr[i]-1 ];
            }

        }  

        cout << ans << '\n';
        
    }

    return 0;
}