/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> qq(q);
        int MAX = 0;
        for (int i = 0; i < q; i++) {
            cin >> qq[i];
            MAX = max(MAX, qq[i]);
        }

        vector<int> crr;
        int a = arr[0];
        int b = arr[0];
        for (int u : arr) {
            if (u < a)  
                a = u;
            if (u > b) 
                b = u;
        }
        crr.push_back(b - a);

        for (int k = 1; k <= MAX; k++) {
            vector<int> brr;

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    brr.push_back(arr[i] ^ arr[j]);
                }
            }

            partial_sort(brr.begin(), brr.begin() + n, brr.end());


            for (int i = 0; i < n; i++) {
                arr[i] = brr[i];
            }

            a = arr[0];
            b = arr[0];
            for (int u : arr) {
                if (u < a) 
                    a = u;
                if (u > b) 
                    b = u;
            }

            crr.push_back(b- a);

            if (a == b) {
                break;
            }
        }

        for (int i = 0; i < q; i++) {
            int x = qq[i];
            if (x < crr.size()) {
                cout << crr[x] << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}