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

        vector<int> arr(30, 0);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            for (int b = 0; b < 30; b++) {
                if (x & (1 << b))
                    arr[b]++;
            }
        }

        int g = 0;

        for (int b = 0; b < 30; b++) {
            g = __gcd(g, arr[b]);
        }

        for (int k = 1; k <= n; k++) {
            if (g % k == 0)
                cout << k << ' ';
        }

        cout << '\n';
    }

    return 0;
}