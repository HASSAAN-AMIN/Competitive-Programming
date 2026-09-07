/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dfs( int u , int prev , vector<vector<int>> &gr , int &cnt){

    int cc= 0 ;
    
    for( auto v : gr[u]){
        if(v == prev)
            continue;
        cc  += dfs( v , u , gr,  cnt) ;
    }
    if( (1 + cc)%2 ){
        return 1+cc ;
    }else{
        cnt++;
        return 0 ;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while(t--){
        int n;
        cin >> n;

        if(n%2){
            cout << -1 << '\n';
            return 0 ;
        }
        vector< vector<int >> gr (n) ;


        for (int i = 0; i < n- 1; i++) {
            int x ,y ;
            cin >> x >> y ;
            x-- ; y--;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }
        int cnt  = 0 ;
        int x =  dfs( 0 , -1 , gr  ,cnt );

        cout << cnt -1 << '\n';
        
  //  }

    return 0;
}