/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<vector<int>> arr(n);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            arr[x].push_back(y);
            arr[y].push_back(x);
        }

        vector<int> dist(n, -1);
        vector<int> par(n, -1);
        queue<int> q;

        q.push(0);
        dist[0] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : arr[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << dist[i] << ' ';
        }
        cout << '\n';

        if(dist[n-1] != -1){
            vector<int> path;
            for (int v = n - 1; v != -1; v = par[v]) {
                path.push_back(v + 1);
            }
            reverse(path.begin(), path.end());
            for(int x : path)
                cout << x << ' ';
            cout << '\n';
        }
    }

    return 0;
}
