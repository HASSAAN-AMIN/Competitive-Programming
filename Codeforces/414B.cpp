/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int mod = 1e9 + 7  ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while(t--){

        int n , k ; 
        cin >> n >> k ; 

        // range 2000

        // 1 opens branch for every number
        // 2 opens for all even
        // 3 for all 3 multiples
        // 4 for 4 multiples

        // numbers can be equal
        // all lesser or equal to n

        // hmmm

        // base case type ig
        // all same k numbers
        // count of them gonna be n

        // now for each n can we replace last ?
        // if the double exist for sure
        // alright its getting dfs and would work
        // but depth gonna be too large

        // think of dp

        // dp what?
        // for the max len
        // for some n ? 

        // vector<int> dp(k+1);
        // dp[0] = 0 ;
        // dp[1] = n ; // all n  integer niggers
        // 
        // for len 2 think as you know 
        // what possibly could happen ? 
        // n numbers every nigga integer would take itself 2 times
        // which already creates n , yeah ik there are more but think of it
        // is this n somewhat related to previous n ???
        // like it should be or shouldnt be

        // yeah like think like that
        // we already has dp[i-1] sequences
        // ( we getting this we gettting this )
        // okie we already has dp[i-1] sequences
        // out of them how much of them from them 
        // we can append more ?
        // yup dont think about this situaation    1 1 1 1 1 2  and starting 2 earlier
        // yeah coz already covered
        // so after that after that after that
        // of how many of them has multiples like below or equal to n
        // like let say the last number was  umm 9 
        // and n is like 20
        // 9 18  kinda like 20/9
        // for 4 endign and num is 30
        // 30/4 = 7   < - - > 4 8 12 16 20 24 28 
        // sure sure i was double checking

        // how to track of last integers 
        // 2d dp umm  ?
        // think for 1d first 2d is kinda obvv
        // well for 2k constraing this would work
        // still think for 1d dp

        // just do 2d dp let me tryna implement it

        vector< vector<int>  > dp(k+1 , vector<int>(n+1 , 0));
        for (int i = 1; i < n +1 ; i++) {
            dp[0][i] = 0 ;
            dp[1][i] = 1 ;
        }

        for (int i = 1; i < k  ; i++) {

            for (int j = 1; j <= n; j++) {
                if( dp[i][j]){
                    int cnt = j ;
                    while( cnt <= n){
                        dp[i + 1][cnt] += dp[i][j];
                        dp[i + 1][cnt] %= mod;

                        cnt += j ;
                    }
                }
            }
        }

        // cout << '\n'  << '\n' ;
        // cout << "dp array :  \n\n"  ;
        // for (int i = 0; i < k+1 ; i++) {
        //     for (int j = 0; j <= n; j++) {
        //         cout << dp[i][j] << ' ' ;
        //     }
        //     cout << '\n' ;
        // } 
        // cout << '\n'  << '\n' ;


        int ans  = 0 ;
        
        for (int i = 1; i <= n; i++) {
            ans += dp[k][i];
            ans %= mod; 
        }
        cout << ans << '\n' ;


        
    // }

    return 0;
}