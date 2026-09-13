/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;



vector<  pair<int, int > > factors(int n){
    vector< pair< int , int> > ans ;
    for (int i = 2; i*i <= n; i++){
        int cnt = 0 ;
        while(n % i == 0){
            cnt++;
            n /= i;
        }
        if(cnt)
            ans.push_back({i , cnt}); 
    }
    if( n > 1)
        ans.push_back({ n , 1 });
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
   // cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--;
        }

        vector<int> vis(n , false) ;
        vector<int> cycles;

        for (int i = 0; i < n; i++) {
            if(vis[i])
                continue;
            int idx = i ;
            int cnt = 0; 
            while(!vis[idx]){
                cnt++;
                vis[idx] = true;
                idx = arr[idx];
            }
            cycles.push_back(cnt);

        }
        
        // we just need lcm of the cycles array

        vector<int> mpow(n+1 , 0 ) ;
        for (int i = 0; i < cycles.size(); i++) {
            
            vector<pair< int , int>>  it =  factors(cycles[i]);
            
            for (int i = 0; i < it.size(); i++) {
                mpow[it[i].first] = max( mpow[it[i].first] , it[i].second) ;
            }

        }

        long long lcm = 1;
        const long long MOD = 1e9 + 7;

        for (int i = 2; i < n+ 1; i++) {
            for (int j = 0; j < mpow[i]; j++) {
                lcm = (lcm * i) % MOD ;
            }
        }


        cout << lcm << '\n';
        
    }

    return 0;
}