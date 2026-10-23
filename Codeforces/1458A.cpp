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
    // cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m ;
        cin >>m ;

        vector<long long> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort( arr.begin() , arr.end() ) ;
        vector<long long> brr(m);
        for (int i = 0; i < m; i++) {
            cin >> brr[i];
        }

        long long ggs = 0 ;

        for (int i = 1; i < n; i++) {
            ggs = __gcd(  ggs , arr[i]-arr[0]); 
        }


        for (int i = 0; i < m; i++) {
            cout << __gcd( ggs ,  arr[0] + brr[i]) << ' ';
        }
        cout << '\n'; 


        
    }

    return 0;
}