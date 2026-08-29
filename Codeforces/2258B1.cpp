/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m ;
        cin >> m ;

        vector<int> arr(n);
        int t = 0 ;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
            if( arr[i] == 2)
                t++;
        }
        int a = n+ t ;

        vector<int> brr( m + 3 ) ;  
        
        for (int i = m; i > 0 ; i--) {
            brr[i] = brr[i + 1] + mp[i];
        }
        

        int b = 0 ;
        int l = -1 ;
        for( auto u  : mp){
            //cout << u.first << ' ' << u.second  << '\n';
            if( u.first % 2 == 0)
                if( u.second > b){
                    l = u.first;
                    b = u.second;
                }
        }
        int e =  0;
        for (int i = 0; i < n; i++) {
            if( 2*arr[i] == l)
                e++;
        }

        int ans = 0 ;

        for (int i = 1 ; i <= m; i++) {
            
            int cur = mp[i] + brr[i+1] ;
            if( 2*i <= m)
                cur += mp[2*i] ;

            ans = max( ans, cur);
        }


        // cout << " l :  " << l << '\n';
        // cout << " e :  " << e << '\n';
        // cout << " b :  " << b << '\n';
        cout <<  ans  << '\n';

        //cout << a << '\n' ;

        
    }

    return 0;
}

// 5 8 
// 4 4 8 8 8