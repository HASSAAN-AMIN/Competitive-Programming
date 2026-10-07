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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long ans = 0 ; 

        unordered_map < int  , int > mp ;
        unordered_map< int , pair<int , int>  > prev ; 

        vector<int> brr(n) ;

        for (int i = 4; i < n; i++) {
            int u =   arr[i-4] + arr[i-2] - arr[i] ; 

            ans += mp[u];
            
            if( i > 5 ){
                if( brr[i-2] == u ){
                    ans-- ;
                }
            }
            if( i > 7 ){
                if( brr[i-4] == u ){
                    ans-- ;
                }
            }
            // if( mp[ u] ){
            //     if( i %2 ){
            //         if( prev[u].second < i - 4){
            //             mp[u]++;    
            //         }
            //         prev[u].second = i ; 
            //     }else{
            //         if( prev[u].first < i - 4){
            //             mp[u]++;    
            //         }
            //         prev[u].first = i ; 
            //     }
            // }else{
            mp[ u]++ ;
            brr[i] = u ;
            //     if( i %2){
            //         prev[u].first =  -1e4 -10 ;
            //         prev[u].second = i ;
            //     }else{
            //         prev[u].second =  -1e4 -10 ;
            //         prev[u].first = i ;
            //     }
            // }

        }

        // for( auto u : mp){

        //     ans += (u.second * (u.second -1 ))/2 ; 
        // }


        cout << ans << '\n' ;


        
    }

    return 0;
}