/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
    // for (int i = 0; i < t; i++) {
        // if(i == 12){
        //     int n;
        //     cin >> n;
        //     int w;
        //     cin >> w ;
        //     vector<int> arr(n);
        //     for (int i = 0; i < n; i++) {
        //         cin >> arr[i];
        //     }
        //     cout << n << w ;
        //     for (int i = 0; i < n; i++) {
        //         cout << arr[i] ;
        //     }
        // }

        int n;
        cin >> n;
        int w;
        cin >> w ;

        // int ll = log2(w );
        // w = (1 << ll) ;
        // cout  << "w is  : " << w << '\n' ;

        vector<int> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int cnt = 0 ;
        sort( arr.begin() , arr.end()) ;
        long long  sum = 0 ;
        for (int i = n-1; i >= 0 ; i--) {
            if( sum + arr[i] > w){
                sum = 0 ;
                cnt++;
            }else{
                sum += arr[i]; 
            }
        }
        if( sum > w)
            cnt++;
        cout << cnt +1 << '\n' ;


     //   long long x =  accumulate( arr.begin() , arr.end() , 0ll ) ;

     //   cout << ceil((x*1.0f) / w) << '\n' ;

        // sort( arr.begin() , arr.end()) ;
        // int ans = 0 ;   
        // vector<bool> vis( n , false) ;
        // int cnt = 0 ; 
        // int crnt  = w ; 
        // while( cnt != n ){
        //     int l = 0 ; 
        //     int r = n-1 ;
        // }


    }

    return 0;
}