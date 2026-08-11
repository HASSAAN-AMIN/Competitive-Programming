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

    int n , c; 
    
    cin >> n >> c ;
    
    vector<int> arr(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // c's + v's - c's_in_stroke?

    // dp state best score + cs in segment
    //
    // ans = cnt + best 
    const int sz=  5e5 + 1 ;
    vector<int> dp( sz , 0) ;
    int cnt  = 0 ;
    int ans = 0 ;
    for (int i = 0; i <n; i++) {

        if( arr[i] == c){
            cnt++;
            continue;
        }

        dp[arr[i]] = max( dp[arr[i]] , cnt)  +1 ;         

        ans = max( ans , dp[arr[i]] - cnt) ;
    }
    cout << cnt + ans << '\n' ;

    

    return 0;
}