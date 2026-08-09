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
        int k;
        cin >> n >> k;

        string s;
        cin >> s;

        string t = s;
        s += s[0];

        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == '1' && s[i + 1] == '0'){
                t[i] = '0';

                if(i + 1 == s.size() - 1)
                    t[0] = '1';
                else
                    t[i + 1] = '1';
            }
        }

        int ans = 0, cnt = 0;

        for(int i = 0; i < t.size(); i++){
            if(t[i] == '1')
                ans++;

            if(i & 1 && t[i] == '1')
                cnt++;
        }
        cout << cnt << ' ' << ans - cnt << '\n';
    }

    return 0;
}