/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s ,t ;
    cin >> s >> t ;

    int cnt  = 0  ;
    
    for( char c : s){
        if(c == '+')
            cnt++;
        else
            cnt--;
    }
    int q  = 0 ;
    int is = 0 ; 
    for( char c : t){
        if(c == '?')  
            q++;
        else
            if( c == '+')   
                is++;
            else
                is--;
    }
    double ans = 0.0 ;

    if( q == 0 )    
        ans = ( cnt == is) ;
    else{

        if( abs(cnt - is)  > q ){
            ans = 0;
        }else{
            long long k =  1ll << q ;
            int x = (cnt - is + q) / 2 ;

            long long c = 1;

            for (int i = 1; i <= x; i++) {
                c = c * (q - i + 1) / i;
            }

            ans = 1.0*c / k;


        }
    }
    cout << fixed << setprecision(12) << ans << '\n'; 
    return 0;
}