/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>


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
        
        unordered_map<int , int> mp ;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++ ;   
        }

        vector<int> brr ;
        // int lo = 1e9 ;
        for( auto u : mp){
            brr.push_back(u.second); 
        }

        sort( brr.begin() , brr.end()) ;

        for( int c=)

        // int ans = 0 ;
        // for( auto u : mp){
        //     ans += u.second - lo ; 
        // }
        // int ans2 = 0 ; 

        // unordered_map<int , int> mp2 ;
        // for( auto u : mp){
        //     mp2[u.second]++;
        // }
        // int hi = -1e9; 
        // for( auto u : mp2){
        //     hi = max( hi , u.second); 
        // }
        // for( auto v : mp2){
        //     if( v.second != hi){
        //         ans2 += v.first;
        //     }
        // }
        // if( ans2 > 0) 
        //     cout << min( ans , ans2) << '\n'; 
        // else
        //     cout << ans << '\n' ;
    }

    return 0;
}