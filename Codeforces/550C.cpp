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

    string s;
    cin >> s;

    int n = s.size();

    for (int x = 0; x < 1000; x+= 8) {


        string t = to_string(x);

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (j < t.size() && s[i] == t[j]) {
                j++;
            }
        }

        if (j == t.size()) {
            cout << "YES\n";
            cout << t << '\n';
            return 0;
        }
    }

    cout << "NO\n";



    return 0;
}