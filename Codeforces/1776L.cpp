/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
   // cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;

        int  p = 0;
        int m  = 0 ;
        for( char c : s){
            if(c == '+')
                p++;
            else
                m++; 
        }

        int q; 
        cin >> q;

        while(q--){
            long long x ,y;
            cin >> x >> y  ;
            
            if( p == m){
                cout << "YES\n";
                continue;
            }
            if (x == y) {
                cout << "NO" << '\n';
                continue;
            }
            // if  
            // a times x +
            // p-a times y +
            // b times x  -
            // m-b times  y -

            // ax - bx  + py - ay  -my + by  
            // equals 0 
            // ( a -b )x - ( a- b)y + py - my
            // a-b  = k
            // kx -ky + py -my = 0
            //  kx + y( -k+ p - m) = 0 
            // kx + ( p-m - k)y = 0 
            // kx + tot y  - ky = 0 
            // k ( x- y) =  - tot y
            // k =  (tot*y) / (y - x)

            if(  ((p-m)*y) % ( y- x) != 0 )
                cout << "NO" << '\n' ;
            else{
                if(  (((p-m)*y)/( y- x)) >  p || (((p-m)*y)/( y- x)) < -m  )
                    cout << "NO" << '\n';
                else
                    cout << "YES" << '\n' ;
            }
            
        }

    }

    return 0;
}