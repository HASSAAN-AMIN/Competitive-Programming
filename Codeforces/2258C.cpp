/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int get ( int a  , int  b  , int c){

    cout << '?' << ' ' << a << ' ' << b  <<  ' ' << c << '\n' ;
    int x ;
    cin >>x ;
    return  x ;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        // n is 1000

        // 3n queries
        
        // diameter
        // omg i have studied this

        // diameter 
        // pick any find furthest
        // take furthest
        // find furthest
        // 2nd and 3rd have diameter
        // nvm increases 3n 
        // nvm i should check
        // n-1 + t
        // n-2 + d-t
        // 2n -3 + d ? 
        // worsst 2n-3 + n- 1 
        // 3n- 4 ? omg 


        int a = 1, b = 1, d = 0;

        for (int i = 2; i < n + 1; i++) {
            if (d == n - 1) 
                break;
            if (get(1, i, d + 1)) {

                int cur = d + 1;
                while (cur < n && get(1, i, cur + 1))
                    cur++;
                a = i;
                d = cur;
            }
            // else if (get(b, i, d + 1)) {
            //     int cur = d + 1;
            //     while (cur < n && get(b, i, cur + 1)) 
            //         cur++;
            //     a = i;
            //     d = cur;
            // }
        }
        for (int i = 2; i < n +1 ; i++) {
            if( i != a ){
                if (get(a, i, d + 1)) {
                    int cur = d + 1;
                    while (cur < n && get(a, i, cur + 1))
                        cur++;
                    b = i;
                    d = cur;
                }
            }
        }
        cout << '!' << ' ' << a << ' ' << b << ' ' << d << '\n';
        
    }

    return 0;
}