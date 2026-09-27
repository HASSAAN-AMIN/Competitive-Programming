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
        int k; 
        cin >> k ;
        k--;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long ans  = 0 ;

        vector<int> brr;  

        for (int i = 0; i < n; i++) {
            if (i >= k && i < n - k) 
                ans += arr[i];            
            else
                brr.push_back(arr[i]);
        }

        k =  min( k, n-k ) ;
        for (int i = 0; i < k; i++) {
            ans += max(brr[i], brr[brr.size() - 1 - i]);
        }

        cout << ans << '\n';
        
        

        
    }

    return 0;
} 