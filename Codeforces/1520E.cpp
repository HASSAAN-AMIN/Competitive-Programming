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

        string s;
        cin >> s;

        
        vector<int> arr;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                arr.push_back(i - arr.size());
            }
        }
        if( arr.size() == 0 ){
            cout << 0 << '\n'; 
            continue;
        }
        int mid = arr[arr.size() / 2];

        long long ans = 0;

        for (auto x : arr) {
            ans += abs(x - mid);
        }

        cout << ans << '\n';

        
    }

    return 0;
}