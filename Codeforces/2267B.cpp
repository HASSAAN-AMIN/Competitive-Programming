/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
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

        vector< int > arr(n);

        priority_queue< pair<int, int>   >pq  ;

        unordered_map< int , int  > mp ;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++ ;
        }

        vector < pair< int , int >> brr; 
        for( auto u :mp){
            pq.push( { u.first  , u.second}) ;
            brr.push_back( { u.first  , u.second}) ;
        }
        sort( brr.rbegin() , brr.rend()); 


        bool sus =true ;


        while( sus) {

            sus = false;

            for (int i = 0; i < brr.size(); i++) {
                if(brr[i].second == 0)
                    continue;
                brr[i].second--;
                cout << brr[i].first  << ' ' ;
                sus =true ;
            }
            

        }


        // while( !pq.empty()){

        //     pair<int , int>  x = pq.top(); 
        //     if( x.second == 0 ){
        //         pq.pop() ;
        //         continue; 
        //     }
        //     cout << x.first << ' ' ;
        //     pq.pop();
        //     x.second--;
        //     pq.push( x) ;
        // }
        cout << '\n' ;




        // max  then rem 


        


        
    }

    return 0;
}