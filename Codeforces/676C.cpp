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

    int t = 1;
    // cin >> t;
    while(t--){
        
        int n , k;
        cin >> n >> k ;

        string s ; 
        cin >> s ;

        int l = 0 ;
        int r = 0 ;

        int ans  = 0 ;

        int a  = 0 ;
        int b  = 0 ;
        
        while(r < n){
            if(s[r] == 'a')
                a++;
            else
                b++;

            while(min(a,b) > k){
                if(s[l] == 'a')
                    a--;
                else
                    b--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }

        cout << ans << '\n' ;



    }

    return 0;
}   