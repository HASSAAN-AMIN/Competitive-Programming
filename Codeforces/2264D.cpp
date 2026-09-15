/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check(string s) {
    int cnt[3] = {1, 0, 0};
    int rem = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (i % 2 == 0)
                rem = (rem + 2) % 3;
            else
                rem = (rem + 1) % 3;
        }

        cnt[rem]++;
    }

    return max({cnt[0], cnt[1], cnt[2]})- min({cnt[0], cnt[1], cnt[2]}) <= 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        if (n == 2) {
            cout << "10\n";
            continue;
        }

        int a = n / 3;
        int b = 2 * n / 3;

        bool sus = false;

        for (int x = a; x <= a + 1; x++) {
            for (int y = b; y <= b + 1; y++) {
                for (int l = 0; l <= 1; l++) {

                    if (x >= y)
                        continue;

                    string s(n, '0');

                    s[x - 1] = '1';
                    s[y - 1] = '1';

                    if (l)
                        s[n - 1] = '1';

                    if (check(s)) {
                        cout << s << '\n';
                        sus = true;
                        break;
                    }
                }
                if(sus)
                    break;

            }
            if(sus)
                break;
        }


    }
}