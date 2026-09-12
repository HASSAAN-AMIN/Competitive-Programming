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
   // cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--;
        }

        vector<int> vis(n , false) ;
        vector<int> cycles;

        for (int i = 0; i < n; i++) {
            if(vis[i])
                continue;
            int idx = i ;
            int cnt = 0; 
            while(!vis[idx]){
                cnt++;
                vis[idx] = true;
                idx = arr[idx];
            }
            cycles.push_back(cnt);
        }
        
        // we just need lcm of the cycles array

        const long long MOD = 1e9 + 7;

        long long lcm = 1;

        for(int x : cycles){
            lcm = (lcm / __gcd(lcm, (long long)x) % MOD) * x % MOD;
        }

        cout << lcm << '\n';
        
    }

    return 0;
}