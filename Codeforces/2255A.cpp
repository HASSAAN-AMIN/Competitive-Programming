/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include "1.h"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int a , b,   c;
        cin >> a >> b >> c;



        cout << min(max({a , b, c}) - min({a , b , c}), a +b + c -  max({a , b, c}) - min({a , b , c})) << '\n';





        
    }

    return 0;
}