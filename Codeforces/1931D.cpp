/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
#include <map>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x  , y; 
        cin >> x >> y;


        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // (a + b ) mod x = 0 
        // a mod x +  b mod x  = x 
        
        // ( a - b ) mod xy  = 0 ;
        // a mod  y - b mod y
        // then 
        // a mod y = b mod y


        vector<int> brr ( n ) , crr(n) ;

        for (int i = 0; i < n; i++) {
            brr[i] = arr[i]%x;
            crr[i] = arr[i]%y ;
        }

        // unordered_map<  pair<int , int > , int > mapy ;
        // woah new info unouredered map cant have pair key
        map < pair<int , int>   ,  long long  > mapy;
        
        long long ans =  0;
        
        for (int i = 0; i < n; i++) {


            ans += mapy[ { ((x- brr[i])%x)  , crr[i]}  ] ;

            mapy[{brr[i] , crr[i]}]++ ;
        }

        cout << ans << '\n' ;


        
    }

    return 0;
}