/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<int> fun( long long s){

    vector<int > arr;

    for (int i = 0; 1ll*i *i < s; i++) {
        if( s% i == 0)  {
            arr.push_back(i);
            if( i*i != s){
                arr.push_back(s/i);
            }
        }
    }

    return arr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        
        long long s ;
        int q ;
        cin >> s >> q ;

        vector<int> arr = fun( s);
        sort( arr.begin() , arr.end()) ;
        
        while(q--){
            int x ;
            int y;
            cin >> x >> y ;
            int ans = 0;

            for (int i = 0; i < x; i++) {
                ans += upper_bound() ;
            }


        }

        
    }

    return 0;
}