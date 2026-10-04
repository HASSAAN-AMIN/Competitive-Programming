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

    int t = 1;
   /// cin >> t;
    while(t--){
        int n;
        cin >> n;   
        int v ;
        cin >> v ; 

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }   

        long long ans= 0 ;


        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    if( i+ j+ k +3 <= v)
                        ans = max( ans ,0ll+ arr[i]+ arr[j]+ arr[k]) ;
                }
            }
        }
        cout << ans << '\n' ;


        
    }

    return 0;
}