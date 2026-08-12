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

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> ans(n);

        for(int k = 0; k < n; k++) {

            int l = 0;
            int r = k;

            while(l < r) {

                int mid = l + (r - l) / 2;

                if(arr[mid] >= k - mid + 1) // holy moly
                    r = mid;
                else
                    l = mid + 1;
            }

            ans[k] = k - l + 1;
        }

        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";

        cout << "\n";
        
    }

    return 0;
}