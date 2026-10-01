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
    cin >> t;
    while(t--){
        
        long long n;
        cin >> n ;

        vector<long long> arr(n);
        vector<long long> brr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i] >> brr[i] ;
        }

        sort( arr.begin() , arr.end()) ;
        sort( brr.begin() , brr.end()) ;


        cout << ( arr[n/2]- arr[(n-1)/2] +1ll )*(( brr[n/2]- brr[(n-1)/2] +1ll )) << '\n';

    }

    return 0;
}