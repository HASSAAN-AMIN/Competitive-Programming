/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int u, int p, int ii,vector<vector<pair<int,int>>> &gr, vector<int> &dp) {

    for(auto [v, idx] : gr[u]) {

        if(v == p)
            continue;
        dp[v] = dp[u];
        if(idx < ii)
            dp[v]++;
        dfs(v, u, idx, gr, dp);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;


        // vector< bool > vis( n , false);
        // vis[0] = true;
        vector<int > dp( n +1 , 0 );
        dp[1]= 1 ;
        vector<vector<pair<int,int>>> gr(n + 1);
        // int cnt = 0 ;
        for(int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;

            gr[x].push_back({y, i});
            gr[y].push_back({x, i});
        }
        
        dfs(1, 0, 0, gr, dp);

        int ans =  0 ;
        for (int i = 1; i <= n; i++) {
            ans = max(ans , dp[i]) ;
        }
        cout << ans <<'\n' ;


    }

    return 0;
}