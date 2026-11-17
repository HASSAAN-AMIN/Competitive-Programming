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
        int n, q;
        cin >> n >> q;

        vector<long long> arr(n);
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            pref[i + 1] = pref[i] + arr[i];
        }

        while(q--){
            int l, r;
            cin >> l >> r;
            l--;
            cout << pref[r] - pref[l] << '\n';
        }
    }

    return 0;
}
