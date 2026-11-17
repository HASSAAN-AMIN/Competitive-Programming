/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool sus = false;

void dfs(int x, vector<vector<int>> &arr, vector<int> &col, int val){
    col[x] = val;
    for(int u : arr[x]){
        if(col[u] == -1){
            dfs(u, arr, col, !val);
        }
        else if(col[u] == val){
            sus = true;
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

        vector<int> col(n, -1);

        for (int i = 0; i < n; i++) {
            if(col[i] == -1){
                dfs(i, arr, col, 0);
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
