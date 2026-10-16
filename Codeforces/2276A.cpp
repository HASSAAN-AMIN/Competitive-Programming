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
        int a , b ;
        cin >> a >> b; 

        if( a  <=  b ){
            cout << -1 << '\n';
        }else{
            cout << min( b ,  a-b ) << '\n' ;
        }

        
    }

    return 0;
}