/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

// wrong nvm 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
  //  cin >> t;
    while(t--){
        int n;
        cin >> n;
        int q;
        cin  >> q ;


        vector<int> arr(1 << n);

        for (int i = 0; i < (1<<n); i++) {
            cin >> arr[i];
        }

        
        int m = 1 << n;
        vector<int> pre( m ) ;
        vector<int> suf( m ) ;
        pre[0] = arr[0] ;
        suf[m-1] = arr[m-1];

        for (int i = 1; i < m; i++) {
            pre[i] = pre[i-1]|arr[i]; 
        }
        for (int i = m-2; i >= 0; i--) {
            suf[i] = suf[i+1] | arr[i] ;
        }
        
        while(q--){
            int a , b ;
            cin >> a>> b; 

            if( a == 1){
                cout <<( b | suf[1] ) << '\n';
            }else if( a == m){
                cout <<( b | pre[m-2] )<< '\n'; 
            }else{
                cout << ( pre[a-2] | b | suf[a]) << '\n';
            }
        }
        
    }

    return 0;
}