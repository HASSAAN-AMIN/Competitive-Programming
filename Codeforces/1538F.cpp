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
        int l , r ;
        cin >> l >> r; 


        int ans = 0;
        while (l != 0 || r != 0) {
            ans += r - l;
            l /= 10;
            r /= 10;
        }
        cout << ans << '\n';

        
    }

    return 0;
}