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
        //int n;
        //cin >> n;

        string s ;
        cin >> s ;

        int n = s.size() ;
        int cnt=   1 ;


        // for (int i = 1; i < n -1 ; i++) {
        //     if( (s[i-1] == s[i+1 ]) && s[i-1] != s[i]){
        //         cnt++; 
        //         i++;
        //         break;
        //     }
        // }

        int a = 0;
        int b = 0; 
        
        for (int i = 1; i < n - 1; i++) {
            if (s[i - 1] == s[i] && s[i] == s[i + 1])
                a++;
            if (s[i - 1] != s[i] && s[i] != s[i + 1])
                b++;
        }
        if(a)
            cnt++;
        if(b)
            cnt++ ;
        cout << cnt  << '\n' ;
        
    }

    return 0;
}