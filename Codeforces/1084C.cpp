/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 1e9+7 ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        
        string s ;
        cin >> s; 
        long long ans= 1  ;
        int n = s.size() ;
        int cnt = 0 ;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                if (cnt > 0) {
                    ans *= (cnt + 1);
                    cnt = 0;
                }
            }
            ans += MOD ;
            ans %= MOD ;
            if (s[i] != 'a')
                continue;
            cnt++;
        }

        if (cnt > 0) {
            ans *= (cnt + 1);
            ans %= MOD;
        }

        cout << ans -1 << '\n'; 
        
    }

    return 0;
}