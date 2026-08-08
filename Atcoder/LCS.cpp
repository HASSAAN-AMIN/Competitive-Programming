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

    string s, t;
    cin >> s >> t;

    int n = s.size() ;

    int m = t.size() ;

    vector< vector<int> > dp( n+ 1 , vector<int>(m+1 , 0 ));


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] +1 ;
            else
                dp[i][j] = max( dp[i-1][j] , dp[i][j-1]) ;
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j < m +1; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout<< '\n';
    // }

    int i  = n ;
    int j  = m ;

    string ans  = "" ;
    while(i > 0 && j > 0 ){
        if(s[i-1] == t[j-1]){
            ans += s[i-1];
            i--;
            j--;
        }else{
            if( dp[i][j-1] >= dp[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';

    return 0;
}