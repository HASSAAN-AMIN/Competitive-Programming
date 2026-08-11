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

    int n ; 
    cin  >> n ;
    
    vector<int> arr(n) ;

    for (int i = 0; i < n; i++) {
        cin  >> arr[i] ;
    }

    // 0 0
    // 0 1 
    // 1 0 
    // 1 1 


    vector<  vector<int> > dp( n , vector<int>(3, 0)) ;

    // rest
    // contest
    // gym

    dp[0][0] = 0;

    if(arr[0] == 1 || arr[0] == 3)
        dp[0][1] = 1;

    if(arr[0] == 2 || arr[0] == 3)
        dp[0][2] = 1;

    for (int i = 1; i < n; i++) {
        
        dp[i][0] =   max( { dp[i-1][1]  , dp[i-1][2]  , dp[i-1][0] }) ;

        if(arr[i] == 1 || arr[i] == 3) // c
            dp[i][1] = max( dp[i-1][2]  , dp[i-1][0]   ) +1 ;

        if(arr[i] == 2 || arr[i] == 3)
            dp[i][2] = max( dp[i-1][1]  , dp[i-1][0]   ) + 1;
    }

    cout << n- max( {dp[n-1][0] , dp[n-1][1] ,dp[n-1][2]})  << '\n'; 


    return 0;
}