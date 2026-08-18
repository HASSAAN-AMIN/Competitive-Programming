/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


vector<long long> fun( long long s){

    vector<long long > arr;

    for (int i = 1; 1ll*i *i <= s; i++) {
        if( s% i == 0)  {
            arr.push_back(i);
            if( 1ll*i*i != s){
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

        vector<long long> arr = fun( s);
        sort( arr.begin() , arr.end()) ;
        
        vector<long long> at; 

        long long prev = 0 ;
        at.push_back(0);
        for (int i = 0; i < arr.size() ; i++ ) {
            long long cur = (arr[i] - prev)*( s/ arr[i]) ;
            at.push_back(cur + at.back());
            prev  = arr[i] ;
        }


        // cout << " array  : \n" ;
        // for( auto u : at){
        //     cout << u << ' ' ;
        // }
        // cout<< '\n'; 
        

        while(q--){
            long long x ;
            long long y;
            cin >> x >> y ;

            int up = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

            if (up != arr.size() && y <= s / arr[up]) {
                cout << x * y << '\n';
                continue;
            }

            long long ans = 0;

            if (up != arr.size()) {
                ans = at[up + 1];
                ans -= (arr[up] - x) * (s / arr[up]);
            }
            else {
                ans = at.back();
            }

            int upy = lower_bound(arr.begin(), arr.end(), y) - arr.begin();

            if (upy != arr.size()) {
                ans -= at.back() - at[upy + 1];
                ans -= (arr[upy] - y) * (s / arr[upy]);
            }

            cout << ans << '\n';
            
        }

        
    }

    return 0;
}