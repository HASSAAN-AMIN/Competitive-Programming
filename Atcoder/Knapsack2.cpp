/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n  , w ;
    cin >> n >> w ;

    vector<int> wei(n + 1);
    vector<int> arr(n +  1);

    int sum = 0 ;
    for (int i = 1; i <= n; i++) {
        cin >> wei[i] >> arr[i] ;
        sum += arr[i] ;
    }

    vector<long long> dp( sum +1 , INT_MAX );

    dp[0] = 0;    
    for (int i = 1; i <= n; i++) {
        for(int v = sum ; v >= arr[i] ; v--){
            dp[v] = min( dp[v] , dp[v - arr[i]]  + wei[i]);
        }
    }
    
    int ans = 0;

    for (int v = 0; v <= sum; v++) {
        if (dp[v] <= w) {
            ans = v;
        }
    }

    cout << ans << '\n';


    return 0;
}
