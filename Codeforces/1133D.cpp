/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> brr(n);
        for (int i = 0; i < n; i++) {
            cin >> brr[i];
        }
        map<pair<int  ,int > ,int> mp ;
        int ex = 0 ;
        for (int i = 0; i < n; i++) {
            if( arr[i] == 0){
                if(brr[i] == 0)
                    ex++;

                continue;
            }
            int a = brr[i] ;
            int b = arr[i] ;
            int c = __gcd(a , b) ;
            a /= c;
            b /= c; 
            mp[{a , b }]++;
        }
        int ans = 0 ;
        for( auto x : mp){
            ans = max( ans , x.second);
        }

        cout << ans + ex << '\n' ;
        

        
    }

    return 0;
} 