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
        int n, q;
        cin >> n >> q;

        vector<int> arr(n);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if ( __builtin_popcount(arr[i]) % 2 == 0) 
                cnt++;
        }

        // take benefit from small arr[i]
        // take benefit from small k
        
        cout << cnt<< ' ';

        while(q--){
            int p, x;
            cin >> p >> x;

            int o = (__builtin_popcount(arr[p-1]) % 2) == 0;
            int n = (__builtin_popcount(x) % 2) == 0;

            cnt += n - o;
            arr[p-1] = x;

            cout << cnt << ' ';
        }
        cout << '\n';

        
    }

    return 0;
}