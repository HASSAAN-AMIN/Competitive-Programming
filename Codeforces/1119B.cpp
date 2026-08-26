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

    // int t;
    // cin >> t;
    // while(t--){
        
        int n;
        cin >> n;
        int h ;
        cin >> h ;
        
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // sort( arr.begin() , arr.end()) ;

        // 1 2 3 4 5  
        // 7 
        // 5 2
        // 1 4
        int final = 0 ;
        for (int c = 1 ; c <= n; c++) {
            // cout << "c  is  :  " << c << '\n' ;
            // cout << '\n' << '\n' ;
            int ans = 0;
            int hh = h ;
            sort( arr.begin() , arr.begin() +  c ,  greater<int>()) ;
            // 4 4 3 2 1 
            for (int i = 0; i < c; i += 2) {
                // cout  << " i is :  " << i << '\n'; 
                // cout << "hh is : " << hh << '\n'; 
                // cout << " arr[i] : " << arr[i] << '\n' ; 
                // cout << '\n' << '\n' << '\n' ; 
                hh -= arr[i];
                if (hh < 0)
                    break;
                // if( i == c-1 ){
                //     if( hh >=  arr[i] ){
                //         hh -= arr[i]; 
                //         ans++;
                //     }
                //     break;
                // }
                // //int x = max( arr[i] , arr[i+1]);
                // int x = arr[i];
                // if( hh >= x){    
                //     hh -= x;
                //     ans += 2;
                // }else if( arr[i+1]  >= hh){
                //     // hh -= arr[i+1]; 
                //     // ans++;
                //     break;
                // }else{
                //     break;
                // }
            }
            int need = 0;

            for (int i = 0; i < c; i += 2) {
                need += arr[i];
            }

            if (need <= h)
                final = c;
            else
                break;
        }


        cout << final   << '\n' ;
   // }

    return 0;
}


// 5 10
// 3 1 4 2 4
// 3 
// 3 1 
// 4 3 1
// 4 3 2 1 
// 4 4 3 2 1 


// 5 7
// 2 3 5 4 1
// 2 
// 3 2
// 5 3 2 
// 5 4 3 2 
// 5 4 3 2 1 