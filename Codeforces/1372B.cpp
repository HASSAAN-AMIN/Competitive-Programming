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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        //  minimize lcm
        //  maximize gcd

        // cant iterate ofc
        
        // a , n-a

        // a*(n-a) = lcm*hcf
        // an - a_sq = lcm*hcf
        
        // maximum gcd can be like 
        int a = n;


        for (int i = 2; i*i <= n; i++) {
            if( n % i == 0){
                a = i; 
                break;
            }
        }
        cout << n/a << ' ' << n - n/a << '\n' ;

        
    }

    return 0;
}