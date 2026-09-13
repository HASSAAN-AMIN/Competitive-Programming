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
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // a1 first gives the actual mex of the subset
        // numbers below that are all there
        // and that number isnt there

        // 2nd gives   mex of all when all are halvedddddd
        // what it could possibly be

        // mex could increase and decrease
        // if increase means the doubles were there
        // if isnt then the biggies also missing
        // its floor
        // let a num be k
        // k/2 it becomes
        // k/2 if is then mex
        // it means k was in the array ?
        // but could be k+1 also
        //  both we dc ?

        // for a_k  =   y/k  means  y isnt in set B
        // coz thats the mex and isnt there
        // floor of it
        // means 
        // y lies between 
        // y/k * k <=  and    < (y/k +1 )*k
        // so these shouldnt be in set right ?
        //  a_k * k  .. (a_k +1 )*k-1 
        // both included not in set 
        // rest in the set ?

        // range query type shi difference array simple


        vector<int> brr( n+ 2  , 0) ;


        for (int i = 1; i <= n; i++) {
            
            long long l  = arr[i-1]*i ;
            long long r =  ( arr[i-1]+1)*i-1;
            r = min( r , (long long)n-1) ;
            if( l > n-1)
                continue;
            brr[l]++;
            brr[r+1]--;
        }

        int cnt= 0 ;
        for (int i = 1; i < n; i++) {
            brr[i] += brr[i - 1];
            if(!brr[i])
                cnt++;
        }
        if(brr[0] == 0)
            cnt++;

        cout << cnt << '\n';  
        for (int i = 0; i < n; i++) {
            if( brr[i] == 0 )
                cout << i << ' '; 
        }
        cout << '\n';




        
    }

    return 0;
}