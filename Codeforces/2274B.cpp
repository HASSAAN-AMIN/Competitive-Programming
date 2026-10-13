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

        vector<long long> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector< vector<long long> > dp(  n , vector<long long >(2)) ;

        dp[0][0] = arr[0] ;
        dp[0][1] = arr[0] ; 

        long long ans = arr[0] ;
        // col 1   max     : col 2  min
        for (int i = 1; i < n; i++) {
            
            ans = max({ans,arr[i] - dp[i-1][0],arr[i], arr[i] + dp[i-1][0],arr[i] - dp[i-1][1], arr[i] + dp[i-1][1]});


            dp[i][0] = max({arr[i], dp[i-1][0] + arr[i], 2 * dp[i-1][0] + arr[i],dp[i-1][1] + arr[i],2 * dp[i-1][1] + arr[i]});
            dp[i][1] = min({arr[i],dp[i-1][0] + arr[i] , 2 * dp[i-1][0] + arr[i],dp[i-1][1] + arr[i],2 * dp[i-1][1] + arr[i]});
        }

        cout << ans<< '\n'; 



        
    }

    return 0;
}