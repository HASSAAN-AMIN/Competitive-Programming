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

        vector<vector<pair<int, int>>> gr(n);

        for (int i = 0; i < m; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            x--;
            y--;
            gr[x].push_back({y, w});
            gr[y].push_back({x, w});
        }

        const long long INF = 4e18;
        vector<long long> dist(n, INF);
        vector<int> par(n, -1);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dist[u])
                continue;

            for(auto e : gr[u]){
                int v = e.first;
                int w = e.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    par[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << dist[i] << ' ';
        }
        cout << '\n';

        if(dist[n-1] != INF){
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
