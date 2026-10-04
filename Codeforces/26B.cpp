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
    //cin >> t;
    while(t--){
        string s;
        cin >> s ; 
        int n = s.size() ;

        int k = 0 ;

        // vector<int> arr(n);
        // vector<int> brr(n);

        // arr[0] = (s[0] == '(') ; 
        // brr[n-1] = (s[n-1] == ')') ;
        // for (int i = 1; i < n; i++) 
        //     arr[i] = arr[i-1] + (s[i] == '(') ;
        
        // for (int i = n-2; i >= 0 ; i--) 
        //     brr[i] = brr[i+1] + (s[i] == ')') ;
        
        int o =  0 ;
        for (int i = 0; i < n; i++) {
            if( s[i] == '(')
                k++; 
            else if( k > o ){
                o++; 
            }
        }
        

        cout << 2*min( o , k) << '\n'; 
        
    }

    return 0;
}