/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


const int MOD  = 998244353;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;


        // odd place and even place alternate req ig

        // max ans could be 4
        // 2 +2 

        

        int ans = 0;

        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){

                bool sus = true;

                for(int k = 0; k < n; k++){
                    int x = i ;

                    if(k % 2)
                        x = j;

                    if(k / 2 % 2)
                        x ^= 1;

                    if(s[k] != '?' && s[k] - '0' != x){
                        sus = false;
                        break;
                    }
                }

                if(sus)
                    ans++;
            }
        }

        cout << ans << '\n';
        
        
    }

    return 0;
}