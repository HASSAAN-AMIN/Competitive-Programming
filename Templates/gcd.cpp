/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


int gcd(int a, int b) { 
    
    return b == 0 ? a : gcd(b, a % b); 

}

// if c++ 14
// use this builtin -. __gcd( a, b)


// if c++ 17
// use
#include <numeric>
// there exists std::gcd and std::lcm


// TC log( a*b)


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    cout << "cases :  ? " << '\n' ;
    int t;
    cin >> t;
    while(t--){
        int n , m ;
        cout << " nums \n" ;
        cin >> n  >> m ;

        
        cout << gcd(n , m) << '\n' ;
        
    }

    return 0;
}