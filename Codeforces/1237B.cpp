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

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> brr(n);

    for (int i = 0; i < n; i++) {
        cin >> brr[i];
    }

    vector<int> pos(n + 1);

    for (int i = 0; i < n; i++) {
        pos[arr[i]] = i;
    }

    int cnt = 0;
    int mn = n;

    for (int i = n - 1; i >= 0; i--) {

        int p = pos[brr[i]];

        if (p > mn) {
            cnt++;
        }

        mn = min(mn, p);
    }

    cout << cnt << '\n';

    return 0;
}