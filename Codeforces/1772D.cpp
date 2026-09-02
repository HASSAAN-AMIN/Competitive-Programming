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

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int hi = 0 ; 
        int lo = 1e9 ; 

        for (int i = 0; i <n-1 ; i++) { 
            if( arr[i] <  arr[i+1]){
                lo = min( lo , (arr[i] + arr[i+1])/2) ;
            }else if( arr[i] > arr[i+1 ])
                hi = max( hi , (arr[i] + arr[i+1] +1)/2) ;
        }


        if( lo < hi)
            cout << -1 << '\n';
        else
            cout << lo << '\n'; 


        
    }

    return 0;
}