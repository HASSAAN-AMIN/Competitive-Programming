/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <numeric>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    // while(t--){
        int n;
        cin >> n;

        vector<long long> arr(n);

        int z = 0 ;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if( !arr[i])
                z++;
            if(  i != 0 )   
                arr[i] += arr[i-1] ;
        }

        //int sum = accumulate(arr.begin() ,  arr.end() , 0) ;
        long long sum = arr[n-1] ;
        // check -> then
        // 0 allows movement
        if(sum %3  != 0  ){
            cout <<  0 << '\n' ;
            return 0;
        }
        if( sum ==  0 ){
            long long cnt = 0 ;

            for (int i = 0; i < n - 1; i++)
                if (arr[i] == 0)
                    cnt++;
            
            cout << (1ll*cnt*cnt -cnt)/2 << '\n' ;

        }else{

            vector<int> dp0(n , 0);
            vector<int> dp1(n,  0);

            long long k = sum /3 ;

            long long l = 2*k  ;

            for (int i = 0; i < n; i++) {
                if( arr[i] == k)
                    dp0[i] = 1; 
                if( arr[i] == l)
                    dp1[i] = 1 ;
            }
                

            long long ans = 0;
            int c = 0 ;
            for (int i = 0; i < n -1; i++) {
                if(dp0[i] == 1)
                    c++;
                else if( dp1[i] == 1)
                    ans += c;
            }
            cout<< ans << '\n';
        }


    // }

    return 0;
}