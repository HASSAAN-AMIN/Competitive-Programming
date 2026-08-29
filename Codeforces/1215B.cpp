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

    int n;
    cin >> n ;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        int x ;
        cin >>  x;
        if( x > 0 )
            arr[i] = 1;
        else
            arr[i] = -1;
    }

    for (int i = 1; i < n; i++) {
        arr[i] *=  arr[i-1]
    }


    






    return 0;
}