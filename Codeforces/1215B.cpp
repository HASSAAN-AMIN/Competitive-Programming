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
    cin >> n ;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int x ;
        cin >>  x;
        if( x > 0 )
            arr[i] = 1;
        else
            arr[i] = -1;
    }

    // p p p p n n p
    // p p p p n p p

    // for (int i = 1; i < n; i++) {
    //     arr[i] *=  arr[i-1];
    // }  
    // for product till here arr[i] tells
    // cant check all n is large

    // total n*n + n / 2

    // even negs make pos

    // maintain a cnt 
    // of negs

    // when negs become odd , add the combination sum till now
    // maybe ?
    // uhh 


    // why think hard when i can just dp  ? 
    vector<vector<int>> dp(n , vector<int>(2) );


    // col 0 pos   ,  1 neg

    // base
    if( arr[0] >  0){
        dp[0][0] = 1;
        dp[0][1] = 0 ;
    }else{
        dp[0][0] = 0 ;
        dp[0][1] = 1 ;
    }

    for (int i = 1; i < n; i++) {
        if(arr[i] > 0){
            dp[i][0] = 1 + dp[i-1][0];
            dp[i][1] = dp[i-1][1];
        }else{
            dp[i][1] = 1 + dp[i-1][0]; // cross cnt
            dp[i][0] = dp[i-1][1];
        }
    }


    long long pos = 0 ;
    long long neg =  0;

    
    for (int i = 0; i < n; i++) {
        pos += dp[i][0];
        neg += dp[i][1];
    }


    cout << neg << ' ' << pos << '\n';





    return 0;
}