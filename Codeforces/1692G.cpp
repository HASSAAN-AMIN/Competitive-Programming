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

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // adjacent like to be greater must be double  ? kinda
        // like for any 2 power already given would be ofc same
        // but in the end it always just 2 times like more 
        // it can be more
        // so to cmp a_i-1 and a_i even if a_i is greater than half of
        // a_i-1 it would stilll gonna be large like it would become
        // so k +1 numbers
        // we just gotta check with prev ? 

        // let arr for that

        int cnt = 0;

        int ans = 0;
        for (int i = 0; i < n - 1; i++) {

            if (arr[i] < 2 * arr[i + 1]) 
                cnt++;
            else 
                cnt = 0;
            
            if (cnt >= k)
                ans++;
            
        }

        cout << ans << '\n';

        
    }  

    return 0;
}