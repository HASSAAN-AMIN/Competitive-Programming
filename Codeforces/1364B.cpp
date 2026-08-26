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

        vector<int> arr(n);\
        
        vector<bool> vis( n , false);
        vis[0] = true;
        vis[n-1] = true;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // |s1−s2|+|s2−s3|+  . . . 
        //  1 2 6 3 5 
        // 

        for (int i = 1; i < n-1; i++) {
            if( arr[i] >  arr[i-1] && arr[i] >  arr[i+1])
                vis[i] = true;
            else if(arr[i] <  arr[i-1] && arr[i] <  arr[i+1] )
                vis[i] = true;
        }

        int cnt  = 0  ;
        for (int i = 0; i < n; i++) {
            if(vis[i])
                cnt++;        
        }
        cout << cnt << '\n' ;
        for (int i = 0; i < n; i++) {
            if( vis[i] )
                cout << arr[i] << ' ' ;
        }
        cout << '\n';
    
    }

    return 0;
}