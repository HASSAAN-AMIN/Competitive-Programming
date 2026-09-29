/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> foo( vector<int> arr){

    int n = arr.size() ;

    vector<int> sus( n+1 ,0 ) ; 

    for (int i = 0; i < n; i++) {
        if( arr[i] == 0 )
            continue;
        int j = i ; 
        while( j < n &&  arr[j]  == 1  )
            j++ ;
        for (int k = 1; k < j -i+ 1; k++) {
            sus[k]  +=  j-i-k+1 ; 
        }
        i = j -1 ;
    }
    return sus;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
   //  cin >> t;
    while(t--){
        
        int n ,m ; 
        cin >> n >> m;
        int k ;
        cin >>  k ;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> brr(m);
        for (int i = 0; i < m; i++) {
            cin >> brr[i];
        }

        vector<int> fir = foo( arr) ;
        vector<int> sec = foo( brr) ;

        long long ans  =  0 ;


        for (int i = 1; i < fir.size(); i++) {
            if( k%i == 0  &&   k/i < m+1 ){
                ans += 1ll* fir[i] * sec[k/i] ;
            }
        }

        cout << ans << '\n' ;

    }

    return 0;
}