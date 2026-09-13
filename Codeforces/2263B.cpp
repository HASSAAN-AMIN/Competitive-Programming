/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


const int MOD  = 1e9+7 ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n , k ;
        cin >> n >> k ;

        
        if( k < n || k == 2*n){
            cout << -1 << '\n';
            continue;
        }

        vector<vector <int>> arr( n ,  vector<int>(n));

        vector<vector <bool>> vis( n ,  vector<bool>(n , false));
        


        for(int i = 0; i < n; i++) {
            arr[i][i] = k- n + i + 1;
            vis[i][i] = true;
        }

        for(int i = 0; i < k-n; i++) {
            arr[0][i + 1] = i + 1;
            vis[0][i + 1] = true;
        }

        int cnt = k + 1;
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if( !vis[i][j]){
                    arr[i][j] = cnt;
                    cnt++;
                }
            }
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }




        
    }

    return 0;
}