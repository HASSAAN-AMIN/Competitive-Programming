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

    int n ;
    cin >> n ; 

    int q ;
    cin >> q; 
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }   
    // 1 2 4 0 3  5 
    // 1 3 7 7 10 15

    vector<long long> brr(n+ 1 );
    brr[0] = 0 ;
    for (int i = 1; i < n+1; i++) {
        brr[i] = brr[i-1]+ arr[i-1]; 
    }

    while(q--){
        int l , r ;
        cin >> l  >> r ;


        cout << brr[r]- brr[l-1];
        cout << '\n' ;
    }



    return 0;
}