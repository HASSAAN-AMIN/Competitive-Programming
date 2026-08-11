/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <set>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int q ;
        cin >> q;

        vector<int> dp( n ) ;
        dp[0] = -1 ;

        for (int i = 1; i < n; i++) {

            if( arr[i] != arr[i-1] ){
                dp[i] = i - 1 ;
            }else
                dp[i] = dp[i-1] ;
        }
        

        while(q--){
            int l , r;
            cin >> l >> r;
            l--; 
            r--;
            if( dp[r] == -1 || dp[r] < l )
                cout << -1 <<  ' ' << -1 << '\n' ;
            else    
                cout << dp[r] + 1 << ' ' << r + 1 << '\n';
        }

        
    }

    return 0;
}