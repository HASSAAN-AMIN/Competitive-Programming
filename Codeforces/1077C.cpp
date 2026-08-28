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

    // int t;
    // cin >> t;
    // while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        long long sum =  0;

        int maxy = 1e6 ;
        vector<int>  req( maxy + 1 , 0 );
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            req[arr[i]]++;
            sum += arr[i]; 
        }

        vector<int> ans ;
        for (int i = 0; i < n; i++) {
            sum -= arr[i]; 
            req[arr[i]]--;
            if( sum%2 == 0 && sum/2 <= 1e6 &&  req[sum/2]  )
                ans.push_back(i+1) ;
            req[arr[i]]++;
            sum += arr[i];
        }
        cout << ans.size()  << '\n' ;
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' '  ;
        }

        
   // }

    return 0;
} 