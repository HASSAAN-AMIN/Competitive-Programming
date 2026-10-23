/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m ;
        cin >> m ;
        int ans =1  ; 
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
//            arr[i] %= m;

        }

        sort( arr.begin() , arr.end() , greater<int>()); 

        if( n <= m ){
            for (int i = 0; i < n; i++) {
                for (int j = i+1; j < n; j++) {
                    ans = (ans*(( arr[i] - arr[j])%m))%m ; 
                }
            }
            cout << ans  << '\n' ;
        }else
            cout << 0 << '\n' ;


        
    }

    return 0;
}