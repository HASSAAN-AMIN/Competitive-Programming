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

        vector<int> col(n, -1);
        bool sus = false;

        for (int i = 0; i < n && !sus; i++) {
            if(col[i] != -1)
                continue;

            queue<int> q;
            q.push(i);
            col[i] = 0;

            while(!q.empty() && !sus){
                int u = q.front();
                q.pop();

                for(int v : arr[u]){
                    if(col[v] == -1){
                        col[v] = !col[u];
                        q.push(v);
                    }
                    else if(col[v] == col[u]){
                        sus = true;
                        break;
                    }
                }
            }
        }

        if(sus){
            cout << "IMPOSSIBLE\n";
            return 0;
        }

        for (int i = 0; i < n; i++) {
            cout << col[i] + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
