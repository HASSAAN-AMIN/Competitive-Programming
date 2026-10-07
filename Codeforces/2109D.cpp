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
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m , l;
        cin >> m >> l ; 

        vector<int> arr(l);

        for (int i = 0; i < l; i++) {
            cin >> arr[i];
        }
        vector<vector<int>> gr( n) ;

        for (int i = 0; i < m; i++) {
            int u , v;
            cin >> u >>v; 
            u-- ;
            v-- ;
            gr[u].push_back(v);
            gr[v].push_back(u) ;
        }

        queue<int> q; 

        q.push(0);
        vector<bool> vis(n , false) ;
        vis[0] = true; 


        while(!q.empty()){


            
        }




        
    }

    return 0;
}