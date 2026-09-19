/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <numeric>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        int mm = 0 ;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mm = max( mm  ,arr[i] );
        }

        long long cnt = accumulate( arr.begin() , arr.end() , 0ll ) ;

        if( cnt %2 == 1 )
            cout << "NO" << '\n';
        else{  
            if( 2*mm > cnt )
                cout << "NO" << '\n';
            else
                cout << "YES" << '\n'; 
        }


        
    }

    return 0;
}