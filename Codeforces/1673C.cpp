/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <string> 


using namespace std;

const int MOD  =  1e9 + 7 ;
bool check( string s) {
    
    for (int i = 0; i < s.size() / 2 ; i++) {
        if( s[i] != s[s.size() -i-1 ])
            return false; 
    }
    return true; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int m = 4e4 + 1 ;

    vector<int>pb ;
    for (int i = 1; i < m; i++) {
        if( check(to_string(i))){
            pb.push_back(i);
        }
    }
    int sz = pb.size() ;
    vector<int> dp( m) ;
    dp[0] = 1 ;


    for (int i = 0; i < sz; i++) {
        for (int j = 1; j < m; j++) {
            if( j- pb[i] >= 0 ){
                dp[j] = (dp[j]+dp[j-pb[i]])%MOD ;
            }
        }
    }



    
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n]  << '\n';
    }

    return 0;
}