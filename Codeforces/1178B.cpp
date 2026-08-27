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

    string s;
    cin >> s;


    // 1 0 
    // 2 1
    // 3 2 
    // 4 3
    // 5 4   
    
    // wwowwowow

    int cnt = 0 ;
    int tot = 0; 
    // vvovooovovvovoovoovvvvovovvvov
    // voovovvvoo

    for(int i = 0 ; i < s.size() ; i++){
        char c  = s[i] ;
        if( c == 'o'){
            if( cnt >= 2){
                tot += cnt-1 ;
                // cout << "add at idx : " << i << '\n' ;
                // cout << " cnt : " << cnt << '\n';
            }
            cnt = 0 ;
        }else
            cnt++;
    }
    if( cnt >= 2)
        tot += cnt-1 ;



    // cout << "tot is : " << tot << '\n' ;

    // wwowwowow
    

    // voovovvvoo
    long long ans  = 0 ; 
    cnt = 0 ;
    int w = 0;
    for (int i = 0; i < s.size()-1; i++) {
        if( s[i] == 'v')
            cnt++;
        if( i> 0 && s[i] == 'o'){
            if( cnt >= 2 ||  w >= 1){
                if(cnt >= 2)
                    w += cnt-1;
                // cout << "w is : " << w << '\n' ;
                ans += 1ll*(w)*(tot-w) ;
            }
            cnt= 0 ;
        }
    }

  //  cout << "w is : " << w << '\n' ;

    cout << ans << '\n' ;

    return 0;
}