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

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> sol;

        long long ans= 0 ;
        for (int i = 0; i < n ; i++) {
            if( arr[i]  < i +1 ){

                ans += lower_bound(sol.begin() , sol.end() , arr[i]) - sol.begin() ; 


                sol.push_back(i+ 1) ;
            }
        }
        cout << ans  << '\n';
    }

    return 0;
}