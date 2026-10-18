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

    int t = 1;
    cin >> t;
    while(t--){
        
        int n , x;
        cin >> n  >> x;


        long long ans = 0 ;


        for (int i = 1; i < x; i++) {
            for (int j = 1; i+ j < x &&  i*j + i+ j <= n; j++) {
                ans += min( (n-i*j)/(i+j) , x- i-j ) ; 
            }
        }

        cout << ans << '\n'; 
        
    }

    return 0;
}