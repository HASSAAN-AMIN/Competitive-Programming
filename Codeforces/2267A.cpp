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
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        char c  ;
        cin >>c ;
        string s ;
        cin >> s ;

        int cnt = 0; 
        for (int i = 0; i < n/2; i++) {
            if( s[i] != s[n-i-1]){
                cnt+= 2;
                if( s[i] == c)
                    cnt--;
                if( s[n-i-1] == c)
                    cnt--;
            }
        }
        cout << cnt  << '\n';


        
    }

    return 0;
}