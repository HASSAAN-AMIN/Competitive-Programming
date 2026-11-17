/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int x, vector<vector<int>> &arr, vector<bool> &vis){
    vis[x] = true;
    for(int u : arr[x]){
        if(!vis[u]){
            dfs(u, arr, vis);
        }
    }
}

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

        vector<bool> vis(n, false);
        vector<int> reps;

        for (int i = 0; i < n; i++) {
            if(!vis[i]){
                reps.push_back(i);
                dfs(i, arr, vis);
            }
        }

        cout << reps.size() - 1 << '\n';
        for (int i = 0; i + 1 < reps.size(); i++) {
            cout << reps[i] + 1 << ' ' << reps[i+1] + 1 << '\n';
        }
    }

    return 0;
}
