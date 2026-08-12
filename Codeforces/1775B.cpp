/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<vector<int>> arr(n);
        
        unordered_map< int , int >mapy ;


        for (int i = 0; i < n; i++) {
            int x ;
            cin >> x;
            while(x--){
                int a;
                cin >> a;
                mapy[a]++;
                arr[i].push_back(a);
            }
        }

        bool sus = false;
        for (int i = 0; i < n; i++) {
            bool bad = false;
            for (int j = 0; j < arr[i].size(); j++) {
                if( mapy[arr[i][j]]  < 2 )
                    bad = true; 
            }
            if( !bad){
                sus = true;
                break;
            }

        }

        if( sus )
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n' ;
    }

    return 0;
}