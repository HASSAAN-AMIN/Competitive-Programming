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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<pair<int , int>> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i].first;
            arr[i].second = i+1 ;
        }

        for (int i = 0; i < n; i++) {
            int x ; 
            cin >> x;
            arr[i].first -= x; 
        }

        sort( arr.begin() ,arr.end() , greater<pair<int , int>>()) ;

        int ans = arr[0].first ;

        int i = 1 ;

        while( i < n && arr[i].first ==  ans)
            i++;

        ans = i ;
        cout << ans << '\n' ;
        vector<int> sol(ans);
        for (int i = 0; i <ans; i++) {
            sol[i] = arr[i].second; 
        }

        sort( sol.begin() , sol.end()) ;

        for (int i = 0; i < sol.size(); i++) {
            cout <<sol[i] << ' ';
        }
        cout << '\n' ;



        
    }

    return 0;
}