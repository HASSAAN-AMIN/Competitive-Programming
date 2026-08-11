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

    int n ;
    cin  >>  n;
    vector< pair<int, int > > arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second ; 
    }

    // dp state ->
    // dont
    // yes on left
    // yes on right

    vector< vector<int>> dp( n , vector<int>( 3 , 0 ) ) ;

    dp[0][0] = 0; // dont
    dp[0][1] = 1; // throw left

    if (n == 1 || arr[0].first + arr[0].second  <  arr[1].first)
        dp[0][2] = 1; // useless we always throw leftest to left

    
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        
        if (arr[i-1].first + arr[i-1].second < arr[i].first)
            dp[i][0] = max(dp[i][0], dp[i-1][2]);
        
        dp[i][2] = dp[i][0] + 1;

        dp[i][1] = -1;

        if (arr[i].first - arr[i].second > arr[i-1].first) {
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
            if (arr[i-1].first + arr[i-1].second < arr[i].first - arr[i].second)
                dp[i][1] = max(dp[i][1], dp[i-1][2]);
            dp[i][1]++;
        }
    
    }


    cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << '\n'; 


    return 0;
}