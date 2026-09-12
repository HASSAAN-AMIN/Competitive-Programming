/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long foo( vector<int>& pishu){

    sort( pishu.begin() , pishu.end()) ;
    int n = pishu.size();

    long long sum = 0 ;
    long long prev = 0 ;

    for (int i = 0; i < n; i++) {
        sum += 1ll*i*pishu[i]  - prev ;
        prev += pishu[i] ;
    }

    return sum ;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m ;
        cin >>  m;


        vector< vector<int> > pishu( n,  vector<int>(m)) ;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> pishu[i][j];
            }
        }


        vector< vector<int>> rows( 100'000+1 );
        vector< vector<int>> cols( 100'000+1 );


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rows[pishu[i][j]].push_back(i);
                cols[pishu[i][j]].push_back(j);
            }
        }

        long long ans  =  0 ;

        

        for (int i = 0; i < 1e5+1; i++) {
            if( rows[i].size()  < 1 )
                continue;

            ans += foo( rows[i]) ;
            ans += foo( cols[i]) ;
        }

        cout << ans << '\n';        
    }

    return 0;
}