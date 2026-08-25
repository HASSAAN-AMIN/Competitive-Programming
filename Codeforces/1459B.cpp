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


    int n; 
    cin >> n ;


    // 0 
    // 4 
    // 4
    // 2*4 + 4
    // f(x) -> once go on previous  3 new
    // collision

    if(n %2 )
        cout << 2*(n/2 + 1 )*(n/2 + 2 ) << '\n';
    else
        cout << (n/2  +1 )*( n/2 + 1 ) << '\n' ;

    return 0;
}