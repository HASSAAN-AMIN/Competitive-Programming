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

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--;
        }
        vector<int> gap( n ,  0 ) ;
        vector<int> last ( n ,  0 ) ; 
        vector<int> ans  ( n , -1 ) ;

        for (int i = 0; i < n; i++) {
            gap[arr[i]] = max(gap[arr[i]], i + 1 - last[arr[i]]);
            last[arr[i]] = i + 1;
        }
        for (int x = 0; x < n; x++) {
            gap[x] = max(gap[x], n - last[x] + 1);
        }
        for( int x =0  ; x < n ; x++ ){
            for (int j = gap[x]-1 ; j < n && ans[j] == -1 ; j++) {
                ans[j] = x + 1 ;
            }
        }


        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ' ;
        }
        cout << '\n' ;

    }

    return 0;
}