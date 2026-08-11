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

    int n;
    cin >> n; 
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> brr(n);
    for (int i = 0; i < n; i++) {
        cin >> brr[i];
    }

    vector< vector<long long>> dp(n , vector<long long>(2));


    dp[0][0] = arr[0]; 
    dp[0][1] = brr[0] ;

    for (int i = 1; i < n; i++) {
        
        dp[i][0] = max( dp[i-1][0] , dp[i-1][1] + arr[i]);
        dp[i][1] = max( dp[i-1][1] , dp[i-1][0] + brr[i]);
    }
    cout << max( dp[n-1][0]  , dp[n-1][1])  << '\n';

    return 0;
}