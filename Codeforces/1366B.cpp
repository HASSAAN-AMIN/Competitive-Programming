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

    int t;
    cin >> t;
    while(t--){
        
        int n , x  , m ;
        cin >> n >> x  >> m; 

        // vector<int> arr( n , 0 ) ;
        // finally saw a real difference equation question lol
        // nvm n too large for difference array sol
        
        int s = x ;
        int b = x ;
        while(m--){
            int l , r;
            cin >> l >> r ;
            
            if(l <= b && r >= s){
                s = min(s, l);
                b = max(b, r);
            }
            // l--;
            // r--;
            // arr[l]++;
            // arr[r]--;
        }
        // for (int i = 1; i < n; i++) {
        //     arr[i] += arr[i-1] ;
        // }

        // int cnt  = 0 ;
        // for (int i = 0; i < n; i++) {
        //     if(arr[i])
        //         cnt++;
        // }
        cout << b - s + 1  << '\n' ;

    }

    return 0;
}