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

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k;
        cin >>  k; 

        string s ;
        cin >> s ;


        vector< string> arr  ;

        for (int i = 0; i < n/k; i++) {
            
            string ss =  "" ;

            for (int j = i*k; j < i*k + k ; j++) {
                ss += s[j] ;
            }
            arr.push_back(ss) ;
        }


        // for (int i = 0; i < arr.size(); i++) {
        //     cout << arr[i] << '\n' ;
        // }
        
        int m = arr[0].size() ;

        long long ans = 0 ; 
        //cout << "arrsize:  " << arr.size() << '\n' ;

        for (int i = 0; i <  m/2; i++) {
            

            unordered_map< char , int  >  mp ;

            for (int j = 0; j < arr.size(); j++) {
                mp[arr[j][i]]++;
                mp[arr[j][m-i-1]]++;
            }

           // int u  = mp.begin()->second ; 
            // cout << "showing unordered_map : \n\n" ;
            int u =  0 ; 
            for( auto x: mp){
                u = max( u  , x.second) ;
            }
            // cout << "unordered_map end \n" ;

            ans += 2*arr.size() - u ; 
            
            // cout << "u "  << u << '\n';   
            //cout << i << ": "<<  ans << ' ' ; 
        }

        if( k%2){

            unordered_map< char , int  >  mp ;

            for (int j = 0; j < arr.size(); j++) {
                mp[arr[j][(m/2)]]++;
            }

            // int u  = mp.rbegin()->second ; 
            int u =  0 ; 
            for( auto x: mp){
                u = max( u  , x.second) ;
            }

            ans += arr.size() - u ; 

           // cout << "1: "<<  ans << ' ' ; 
            

        }
       // cout << '\n' ;



        cout << ans << '\n' ;


        
    }

    return 0;
}