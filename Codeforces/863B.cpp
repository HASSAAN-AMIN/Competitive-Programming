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

    // int t;
    // cin >> t;
    // while(t--){
    //     int n;
    //     cin >> n;

    //     vector<int> arr(n);

    //     for (int i = 0; i < n; i++) {
    //         cin >> arr[i];
    //     }

        
    // }
    int n  ;
    cin >> n;
    n = n*2 ;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(  arr.begin()  , arr.end() );

    // 3
    // 305 139 205 406 530 206
    // 139 205 206 305 406 530

    // 3
    // 610 750 778 6   361 407
    // 6   361 407 610 750 778


    // bruh small constrain
    // complete searh
    int a  =  1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i+1 ; j < n; j++) {
            vector<int> ppl ;
            for (int k = 0; k < n; k++) {
                if( k == i  || k == j)
                    continue;
                ppl.push_back(arr[k]) ;
            }
            int ans = 0;
            for (int i = 0; i < n-2; i+= 2 ) {
                ans += ppl[i+1]-ppl[i] ;
            }
            a = min( a, ans) ;
        }
    }

    // cout << min(b , a + min ( arr[1] - arr[0] , arr[n-1]-arr[n-2])) << '\n' ;

    cout << a << '\n' ;


    return 0;
}