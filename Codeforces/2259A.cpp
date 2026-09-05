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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int k ;
        cin >> k ;
        // string s ;
        // cin >> s;
        int cnt  = 0 ;
        for (int i = 0; i < n/k; i++) {
            
            bool sus = false;
            for (int j = 0; j < k; j++) {
                char c ;
                cin >> c;
                if( c == '0')
                    sus = true;
            }
            if(!sus) 
                cnt++;
        }



        cout <<cnt << '\n';
    }

    return 0;
}