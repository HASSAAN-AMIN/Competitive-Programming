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
   //  cin >> t;
    while(t--){
        
        
        int n  , m; 
        cin >> n >> m  ; 

        vector < vector<int> > gr(n)  ;

        for (int i = 0; i <m; i++) {
            int l , r ;
            cin  >> l >> r; 
            l--;
            r--;
            gr[l].push_back(r);
            gr[r].push_back(l) ;
        }

        priority_queue<int  , vector<int> , greater<int> > pq; 

        pq.push( 0) ;

        vector<int> arr ;
        vector<bool> vis( n , false);
        vis[0] = true;
        while( !pq.empty()){

            int x = pq.top();
            arr.push_back(x+1) ;
           //  vis[x] = true;
            pq.pop() ;

            for (int i = 0; i < gr[x].size(); i++) {
                int y = gr[x][i] ;
                if(!vis[y]) {
                    vis[y] = true; 
                    pq.push(y) ;
                }
            }


        }   

        for( auto x :arr)
            cout << x << ' ' ;

        cout << '\n' ;

    }       

    return 0;
}