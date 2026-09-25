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

        vector<pair<int, int>> arr(n); 
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first;
            arr[i].second = i;
        }

        sort(arr.begin(), arr.end());


        bool dp[2] = {true, false};

        for (int i = 0; i < n; i++) {
            
            bool x = false;
            bool  y =  false ;
            
            if (dp[0]) {
                if (0 == (arr[i].second&1)) 
                    y = true;
                if (((n-i-1) & 1) == (arr[i].second&1)) 
                    x = true;
            }
            if (dp[1]) {
                if (1 == (arr[i].second&1)) 
                    x = true;
                    
                if (((n - i ) & 1) == (arr[i].second&1)) 
                    y = true;
            }

            dp[0] = x;
            dp[1] = y;
        
        }

        if( dp[0] || dp[1])
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

    }

    return 0;
}

