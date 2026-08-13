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
        
        int k;
        long long x;

        cin >>  k >>  x;


        // 2k-1
        // peak -> k
        // k + (k-1)
        

        // jus binary search

        int l = 0; 
        int r = 2*k-1;

        int ans = 2*k-1;
        

        while (l <= r) {
            int m = l + (r - l) / 2;

            long long s = 0 ;

            if (m <= k) {
                s = m * (m + 1ll) / 2;
            } else {
                s = k * (k + 1ll) / 2ll + (m - k) * (2ll * k - m + k - 1ll) / 2;
                // looks scary but is easy to derive
            }

            if (s >= x) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        cout << ans << '\n';


        
    }

    return 0;
}