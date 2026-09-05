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
        int cnt[3] = {0,0,0};
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] % 2) 
                cnt[0]++;
            else if (arr[i]% 4 == 0) 
                cnt[1]++;
            else 
                cnt[2]++;
        }

        cout << max( {cnt[0] , cnt[1] , cnt[2]}) << '\n' ;


        
    }

    return 0;
}