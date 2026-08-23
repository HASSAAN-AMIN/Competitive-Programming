/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
//#include <unordered_map>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        map<int , int>  mapy;
        vector<int> arr ; 


        for (int i = 0; i < n; i++) {
            int x;
            cin >> x ;
            mapy[x]++;
        }
        int cnt  = 0 ;
        for(auto x : mapy ){
 //           arr.push_back(x.second) ;
            cnt = max( cnt , x.second) ;
        }

//        sort( arr.begin() , arr.end() , greater<int>() ) ;

        //  4 2
        //  6 1
        //  1 3 

        // 6
        // 2 3 2 1 3 1

        // 2 2 2

        // int cnt = 0 ;
        // for( auto x  :arr){
        //     if( cnt == 0 )
        //         cnt += x;
        //     else
        //         cnt -= x;
        //     cnt = abs(cnt); 
        //     // cout << '\n'; 
        //     // cout << "scnd is  : " << x << '\n';
        //     // cout << "cnt is now  : " << cnt << '\n' ;
        // }
        if( 2*cnt >  n  )
            cout << 2*cnt - n << '\n'; 
        else
            cout << n%2 << '\n' ;


        /*
        5
        6
        1 6 1 1 4 4
        2
        1 2
        2
        1 1
        5
        4 5 4 5 4
        6
        2 3 2 1 3 1

        */

    }

    return 0;
} 