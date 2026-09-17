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
        int n;
        cin >> n;

        vector<long long> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // gcd of lcms
        // lcm  >= max a_i
        // gcd_of_lcms <= lcm >= max( a_i)

        long long gg = arr[0] ;
        long long ans =   0 ; 

        for (int i = 1; i < n; i++) {
            long long cur = arr[i] / __gcd(gg, arr[i]) * gg;
            ans =  __gcd( ans , cur);


            gg = __gcd( gg , arr[i]) ;
        }

        cout << ans << '\n' ;
    }

    return 0;
}