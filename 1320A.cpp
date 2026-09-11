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

    int t = 1;
//    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        unordered_map<int , long long> mapy;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mapy[x-i] += x ;
        }
        long long ans =  0 ;
        for( auto u : mapy){
            ans = max( ans , u.second) ;
        }
        cout << ans << '\n';

        
    }

    return 0;
}