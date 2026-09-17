/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int fun( int x  , int n ,vector<int> &dp){

    if(x == n)
        return  0 ;
    if( x > n)
        return n ; 

    return dp[x]; 

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> dp( n) ;

        dp[n-1] = 1 ;

        for (int i = n-2  ; i >= 0; i--) {
            dp[i] = min( dp[i+1] +1 , fun(i+arr[i]+1 , n , dp )  ) ;
        }

        cout << dp[0] << '\n' ;
    }

    return 0;
}