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

        bool sus = false;
        long long sum = 0  ;

        for (int i = 0; i < n; i++) {
            sum += arr[i] ;
            if( sum <= 0 )
                sus = true;
        }
        sum = 0 ;
        for (int i = n-1; i >= 0 ; i--) {
            sum += arr[i] ;
            if( sum <= 0 )
                sus = true;
        }
        if(! sus )
            cout << "YES" << '\n' ;
        else
            cout << "NO" << '\n' ;
    }


    return 0;
}