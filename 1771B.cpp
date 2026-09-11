/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m ;
        cin >> m ;

        // maybe difference array
        // like feels of that
        // not exactyl that
        // build and prefix ssum like type
        // ez problem


        vector<int> cnt(n ,n);

        for (int i = 0; i < m; i++) {
            int x  , y;
            cin >> x >> y;
            x-- ;
            y--;
            if( x > y){
                x = x ^ y;
                y = x ^ y;
                x = x ^ y ;
                // type shi
            }

            cnt[x] = min( cnt[x] , y);
        }

        for (int i = n-2; i >= 0; i--) {
            cnt[i] = min(cnt[i], cnt[i+1]);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans += cnt[i] - i;
        }

        cout << ans << '\n';
    }

    return 0;
}