/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int u , vector<vector<int> >&tree , vector<int>&val ,vector<bool> &vis ,vector<int>& ans){

    vis[u] = true ;

    bool sus = true;

    for( auto v : tree[u]){
        if(val[v] == 0)
            sus = false;
        if( !vis[v])
            dfs( v,  tree , val  ,vis , ans) ;
    }
    if( val[u] == 0 )
        sus = false;
    
    if( sus)
        ans.push_back(u) ;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while(t--){
    //     int n;
    //     cin >> n;

    //     vector<int> arr(n);

    //     for (int i = 0; i < n; i++) {
    //         cin >> arr[i];
    //     }

        
    // }

    int n ;
    cin >> n ; 

    vector<int> val( n+1 );

    vector<vector<int> > tree( n+1 ) ;

    for (int i = 0; i < n; i++) {
        int p , c ;
        cin >> p >> c; 

        if( p == -1) {   
            val[i+1] = c ;
            continue;
        }

        tree[p].push_back( i+1) ;
        val[i+1] = c;
    }
    vector<bool> vis( n+1 , false) ;
    vector<int> ans ;
    for (int i = 1; i <= n; i++) {
        if( !vis[i] ){
            dfs( i , tree ,  val ,vis , ans) ;
        }
    }   

    sort( ans.begin() , ans.end()) ;


    if( ans.size()) 
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ' ;
        }
    else
        cout << -1 << '\n' ;




    return 0;
}