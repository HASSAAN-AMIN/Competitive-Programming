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
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k;
        cin >> k ; 
    
        vector<int> arr(n);
        vector<int> pre(n + 1 ,0 );
        
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }

        
        pre[0] = 0 ; 
        for (int i = 1; i < n +  1; i++){
            pre[i] = pre[i-1] + arr[i-1] ;
            pre[i] %= k;
        }

        long long cnt = 0;


        unordered_map<int , int> mp ;
        for (int i = k ; i < n; i++) {
            mp[pre[ i-k]]++;
            cnt += mp[pre[i+1]];
        }

        cout << cnt << '\n';

    }

    return 0;
}


