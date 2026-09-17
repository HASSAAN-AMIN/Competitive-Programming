/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        int n;
        cin >> n;

        // vector<int> diff( 1e9 +1 , 0 ) ;
        vector< pair<int , int > > diff ;
        while(n--){
            int l ,r  ;
            cin >> l  >> r ;

            diff.push_back({l , 1});
            diff.push_back({r+1 , -1});
            
            // diff[l]++;
            // diff[r+1]-- ;
        }

        bool sus =false;

        int cnt = 0;
        sort( diff.begin() , diff.end()) ;

        for (int i = 0; i < diff.size(); i++) {
            cnt += diff[i].second  ;
            if( cnt > 2){
                sus = true ;
                break ;
            }
        }


        // for (int i = 1; i < 1e9+ 1; i++) {
        //     diff[i] += diff[i-1] ;
        //     if( diff[i] > 2 )
        //         sus = true ;
        // }

        if( sus )
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n'; 



        
    }

    return 0;
}