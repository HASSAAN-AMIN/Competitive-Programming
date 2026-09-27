/*
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
    In the name of Allah, the Most Gracious, the Most Merciful.
*/

#include <iostream>
#include<vector>
#include<algorithm>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;


int next(int x) {
    string s = to_string(x);

    int ans = 0;

    for (char c : s) {
        int u = c - '0';
        ans += u * u;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // 1  1
        // 4  16  37  58  89  145  42  20  4

        set<int> ss = {4, 16, 37, 58, 89, 145, 42, 20};

        vector<int> cc = {4 , 16 , 37 , 58, 89, 145, 42, 20};

        vector<int> idx(n);


        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                idx[i] = -1;
                continue;
            }

            int j = 0;
            while (arr[i] != 1 && ss.find(arr[i]) == ss.end()) {
                arr[i] = next(arr[i]);
                j++;
            }

            if (arr[i] == 1) {
                idx[i] = -1;
                continue;
            }

            for (int k = 0; k < 8; k++) {
                if (cc[k] == arr[i]) {
                    j = k - j;
                    if (j < 0)
                        j += 8;
                    idx[i] = j;
                    break;
                }
            }
        }
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[idx[i]]++;
        }

        long long ans = 0;

        for (auto u : mp) {
            int cnt = u.second;

            ans += cnt * (cnt - 1ll) / 2ll;
        }

        cout << ans << '\n';
    }

    return 0;
}