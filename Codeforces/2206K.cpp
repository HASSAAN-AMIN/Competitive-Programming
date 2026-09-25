/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <numeric> 

using namespace std;

bool foo(int k, int *arr) {
    
    int z = arr[0]; 
    int o = arr[1];
    int ss = 0;
    for (int i = 0; i < 6; i++) 
        ss += arr[i];

    int bb = max(0, k - z);
    int big_bb = min({ k, o, z + o - k, ss - 2*k });

    return bb <= big_bb;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string s ;
        cin >> s ;

        int arr[10] = {};
        for( char c  :s)
            arr[c-'0']++;
        
        

        int l = 0 ;
        int r = n/4 ; 


        while( l <  r){
            int mid = l+ (r-l+1)/2 ; 

            if( foo(mid  ,arr)){
                l = mid ; 
            }else{
                r = mid-1 ;
            }
        }
        cout << l << '\n';
    }

    return 0;
}