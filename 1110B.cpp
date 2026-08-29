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

    // int t;
    // cin >> t;
    // while(t--){
    //     int n;
    //     cin >> n;

    //     vector<int> arr(n);

    //     for (int i = 0; i < n; i++) {
    //         cin >> arr[i];
    //     }

        
    // }

    // ez fricking obvious shit ?
    int n , m , k; 
    cin >> n >> m >> k ; 
    vector<int> arr(n) ;
    for (int i = 0; i < n; i++) {
        cin >> arr[i] ;
    }
    vector<int>gap; 
    for (int i = 0; i < n-1; i++) {
        gap.push_back(arr[i+1]- arr[i] -1 );
    }
    sort(gap.begin() , gap.end() , greater<int>()) ;

    int ans = arr[n-1]- arr[0] +1 ;

    for (int i = 0; i < k-1; i++) {
        ans -= gap[i] ;
    }   
    
    cout << ans << '\n' ;

    return 0;
}