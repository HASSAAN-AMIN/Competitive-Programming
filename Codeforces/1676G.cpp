/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


int dfs( int u  , vector<vector<int>> & tree ,string s,  int &ans     ){

    int cnt = (s[u] == 'W') ? 1 : -1;
    // w++;
    // b--;
    for (auto v : tree[u]) {
        cnt += dfs(v, tree, s, ans);
    }

    if (cnt == 0)
        ans++;

    return cnt;

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<vector<int >> tree( n);


        for (int i = 1; i < n; i++) {
            int x ;
            cin >> x;
            x-- ;
            tree[x].push_back(i);
        }   

        string s ;
        cin >> s;

        int ans =  0 ;
        dfs(0 , tree , s, ans) ;

        cout << ans << '\n';


        
    }

    return 0;
}