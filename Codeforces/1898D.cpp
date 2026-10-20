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
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        int lo  =   1e9 ;
        int hi  = -1e9 ;
        long long ans= 0 ;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> brr(n);
        for (int i = 0; i < n; i++) {
            cin >> brr[i];
        }

        // cout << "lo :" << lo << '\n';
        // cout << "hi :" << hi << '\n';  
        for (int i = 0; i < n; i++) {
            if( arr[i] > brr[i])
                swap( arr[i] , brr[i]) ; 
            hi = max( hi  , arr[i]) ;
            lo = min( lo , brr[i]); 
            ans += abs( arr[i] - brr[i]);
        }

        if( hi -lo > 0 )    
            cout << ans + 2*(hi-lo) << '\n';
        else
            cout << ans << '\n'; 

        


        
    }

    return 0;
}