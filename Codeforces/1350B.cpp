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

        vector<int> arr(n+1);

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        vector<int> dp (n+1, 1 ) ;
        
        // start fill from back ? 
        // no

        // forgot divisors mb

        for (int i = 1; i <= n; i++) {

            for (int j = i * 2; j <= n; j += i) {

                if (arr[i] < arr[j]) {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }

        // for (int i = 0; i < n; i++) {
        //     cout << dp[i+1] << ' '; 
        // }
        // cout << '\n' ; 


        cout << *max_element(dp.begin() , dp.end())   << '\n';



        
    }

    return 0;
}