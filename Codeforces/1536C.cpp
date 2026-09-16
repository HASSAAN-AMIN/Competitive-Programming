/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string s ;
        cin >> s;

        map<pair<int, int> , int> mapy ;

        int d  =  0 ;
        int k  = 0 ;
        
        for( char c : s){
            if( c == 'D')
                d++;
            else
                k++;
            int gc = __gcd(d , k);
            mapy[ {d/gc,k/gc}]++;
            cout << mapy[ {d/gc, k/gc }] << ' ' ;
        }
        cout << '\n'; 


        
        
    }

    return 0;
}