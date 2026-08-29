/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    // 4 8 15 16 23 42

    int in[4] ;
    
    cout << '?' << ' ' << 1 << ' ' << 2  << '\n';
    cin >> in[0] ;
    cout << '?' << ' ' << 2 << ' ' << 3  << '\n';
    cin >> in[1] ;

    cout << '?' << ' ' << 4 << ' ' << 5  << '\n';
    cin >> in[2] ;
    cout << '?' << ' ' << 5 << ' ' << 6  << '\n';
    cin >> in[3] ;
    
    vector<int> arr =  {4 , 8 , 15, 16, 23, 42} ;

    do{
        if( arr[0] * arr[1] == in[0] && 
            arr[1] * arr[2] == in[1] &&
            arr[3] * arr[4] == in[2] &&
            arr[4] * arr[5] == in[3]
        )
            break;

    }while( next_permutation(arr.begin() , arr.end())) ;


    cout << '!' << ' ' ;
    for (int i = 0; i < 6; i++) {
        cout << arr[i]  <<' ' ;
    }
    cout << '\n';




    return 0;
}