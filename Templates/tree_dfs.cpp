/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int v, int parent, vector<vector<int>> &adj, vector<int> &sub, vector<int> &depth){
    sub[v] = 1;
    for(int u : adj[v]){
        if(u == parent)
            continue;
        depth[u] = depth[v] + 1;
        dfs(u, v, adj, sub, depth);
        sub[v] += sub[u];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        int n;
        cin >> n;

        vector<vector<int>> adj(n);

        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        vector<int> sub(n, 0);
        vector<int> depth(n, 0);

        dfs(0, -1, adj, sub, depth);

        for (int i = 0; i < n; i++) {
            cout << sub[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
