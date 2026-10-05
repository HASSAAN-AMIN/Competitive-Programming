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
    // cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> brr(n , 1 );
        vector<int> crr(n, 1);

        for (int i = 1; i < n; i++) {
            if( arr[i] > arr[i-1])  
                brr[i]= brr[i-1] +1 ;
        }
        for (int i = n-2 ; i >= 0; i--) {
            if( arr[i] < arr[i+1])
                crr[i] = crr[i+1] + 1 ;
        }

        int ans = 0 ;
        for (int i = 0; i < n; i++) {
            ans = max( ans , brr[i]) ;
        }

        for(int i = 1; i < n-1; i++){
            if(arr[i-1] < arr[i+1])
                ans = max(ans, brr[i-1] + crr[i+1]);
        }

        cout << ans << '\n';

        


        
    }

    return 0;
}