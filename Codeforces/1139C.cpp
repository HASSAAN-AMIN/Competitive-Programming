/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>


using namespace std;

const int MOD = 1e9 + 7  ;

long long pow( long long  u , long long v){
    long long ans = 1 ;

    while( v ){

        if(v & 1){
            ans = (ans * u )%MOD ;
        }
        u = (u*u)%MOD;  
        v >>=  1; 

    } 
    return ans ;
}

int dfs( int u , vector<vector<int>> &gr , vector<bool > &vis ){

    int sum = 0 ;
    vis[u] = true; 
    for( auto v  : gr[u]){
        if(!vis[v]){
            sum += dfs( v, gr , vis ) ;
        }
    }
    return sum + 1 ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k;
        cin >> k  ; 
        // total - bad ez
        // size of each connected comp -> sigma -> subtract 

        vector< vector<int>> gr( n) ; 
        for (int i = 0; i < n-1 ; i++) {
            int u  , v ;
            cin >> u >> v; 
            int col ; 
            cin >> col ; 
            u--;
            v--;
            if(!col){
                gr[u].push_back(v);
                gr[v].push_back(u); 
            }
        }

        vector< bool > vis( n , false ); 

        long long ans = 0  ;
        for (int i = 0; i < n; i++) {
            if( vis[i])
                continue;

            int s = dfs( i  ,  gr , vis ) ; 

            ans = (ans +  pow( s , k))%MOD ;
        }

        cout << (pow( 1ll*n  , 1ll*k )   - ans + MOD )%MOD << '\n'; 



    }

    return 0;
}