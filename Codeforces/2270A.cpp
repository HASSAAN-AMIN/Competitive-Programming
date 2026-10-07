/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int x , y, r;
        cin >> x >> y>> r; 

        int a = x;
        int b  = y;
        int ans = 0 ; 

        for (int i = -40; i < 40; i++) {
            for (int j = -40; j < 40 ; j++) {
                if( (x-i)*(x-i) + (y-j)*(y-j) <= r*r){
                    if( ((x-i)*(x-i) + (y-j)*(y-j)) >=  ans){
                        a = i;
                        b =j ;
                        ans =  ((x-i)*(x-i) + (y-j)*(y-j));
                    }
                }
            }       
        }
        cout << a <<' ' << b << '\n' ;
        
    }

    return 0;
}