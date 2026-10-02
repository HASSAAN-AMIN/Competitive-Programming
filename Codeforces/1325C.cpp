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
  //  cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<vector<pair<int, int>>> gr(n) ;

        for (int i = 0; i < n-1 ; i++) {
            int u, v;
            cin >> u >> v  ;
            u--;
            v-- ;
            gr[u].push_back({v, i});
            gr[v].push_back({u, i}); 
        }
        vector<int> ans( n -1 , -1 ) ;
        int cnt = 0 ; 
        for (int i = 0; i < n - 1; i++ ) {
            if( gr[i].size() > 2 ){
                for (int j = 0; j < gr[i].size(); j++) {
                    ans[gr[i][j].second] = cnt ;
                    cnt++ ;
                }
                break;
            }
        }

        for (int i = 0; i < n-1; i++) {
            if( ans[i] == -1 ){
                ans[i] = cnt;
                cnt++;
            }
        }
        
        for (int i = 0; i < n-1; i++) {
            cout << ans[i] << '\n' ;
        }
        // cout << '\n' ; 



    }

    return 0;
}