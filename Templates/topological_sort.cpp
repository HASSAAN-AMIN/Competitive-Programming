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
        vector<int> indeg(n, 0);

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            arr[x].push_back(y);
            indeg[y]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if(indeg[i] == 0)
                q.push(i);
        }

        vector<int> order;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            order.push_back(u);

            for(int v : arr[u]){
                indeg[v]--;
                if(indeg[v] == 0)
                    q.push(v);
            }
        }

        if(order.size() != n){
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        for(int x : order)
            cout << x + 1 << ' ';
        cout << '\n';
    }

    return 0;
}
