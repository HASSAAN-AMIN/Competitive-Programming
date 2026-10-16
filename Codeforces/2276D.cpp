/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;



void dfs( int &cnt , int u , vector<vector<int>> & arr , vector<bool>& vis , bool &sus , vector<bool>&col , bool c= true){
    if( sus )      
        return ;

        
    vis[u] = true ; 
    col[u] = c  ; 

    for( int v : arr[u]){
        if(!vis[v]){

        cnt++;
            dfs( cnt ,  v ,arr,   vis , sus ,  col ,  !c ) ; 
        }
        // else{
        //     if( col[v] == c){   
        //         sus = true;
        //         return;
        //     }
        // }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int m ;
        cin >> m;
        
        vector<vector<int> > arr(n ,vector<int>());

        for (int i = 0; i < m; i++) {
            int u , v;
            cin >>u >> v;
            u--;
            v--;
            arr[u].push_back(v);
            arr[v].push_back(u);
        }

        vector< bool > vis( n , false) ;
        vector<bool > col( n , false ) ;
        bool sus = false;

        bool yes = false ;
        int cnt = 0 ; 
        dfs( cnt , 0 ,arr,   vis , sus ,  col  ) ; 
        for (int i = 0; i < n; i++) {
            if(!vis[i]){
                dfs(  cnt ,i ,arr,   vis , sus ,  col  ) ; 
                yes= true; 
            }
        }

        bool is = false; 
        bool sus2 = false;

        for (int i = 0; i < n; i++) {
            if (arr[i].size() == 0 ) 
                is = true;
            if (arr[i].size() == n - 1) 
                sus2 = true;
        }

        if (is)
            cout << "Brain Melt" << '\n';
        else if (yes || !sus2 || m != n - 1)
            cout << "Many" << '\n';
        else
            cout << 2 << '\n';

        
    }

    return 0;
}