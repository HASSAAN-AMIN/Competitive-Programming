#include <bits/stdc++.h>
using namespace std;



const long long INF = (1ll << 62);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int tt = 1; 
    cin >> tt;
    while (tt--)
    {
        vector<long long> keys(26, INF);
        int temp;
        for (int i = 0; i < 26; i++) {
            cin >> temp;
            if (temp != -1) keys[i] = temp;
        }
        int m; cin >> m;
        char  x, y, z;
        vector<pair<int, pair<int,int>>> chords(m);
        for (int i = 0; i < m; i++)
        {
            cin >> z>>x>>y;
            chords[i] = { z - 'a' , {x - 'a', y - 'a'} };
        }
        for (int i = 0; i < 27; i++)
        {
            for (auto& v : chords)
            {
                if (keys[v.second.first] == INF || keys[v.second.second] == INF) continue;
                keys[v.first] = min(keys[v.second.second] + keys[v.second.first], keys[v.first]);
            }
        }
        string s;
        cin >> s;
        long long ans = 0;
        for (auto& v : s)
        {
            if (keys[v - 'a'] == INF) {
                ans = -1; break;
            }
            ans += keys[v - 'a'];
        }
        cout << ans << '\n';
    }

}