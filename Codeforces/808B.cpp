/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <iomanip>

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

    int n , k ;
    cin >> n >> k  ;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long sum = 0 ;
    long long crnt = 0 ;

    for (int i = 0; i < k; i++) {
        crnt += arr[i];
    }
    sum = crnt ;
    for (int i = k ; i < n; i++) {
        crnt -= arr[i-k];
        crnt += arr[i] ;
        sum += crnt;
    }
    cout << fixed << setprecision(12) << sum/(n-k+1.0) << '\n';



    return 0;
}