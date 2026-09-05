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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int>  brr(n) ;
        vector<int>  crr(n) ;

        bool st = false;
        for (int i = 0; i < n; i++) {
            if(arr[i] == 1){
                st = true;
                brr[i] = 1;
            }
            else if( arr[i] == -1){
                if(st)  
                    brr[i] = 0;
                else{
                    brr[i] = 1 ;
                    st = true;
                }
            }else{
                brr[i] = 0;
            }
            
        }
        st = false;
        for (int i = n-1; i  >= 0 ; i--) {
            if(arr[i] == 1){
                st = true;
                crr[i] = 1;
            }
            else if( arr[i] == -1){
                if(st)  
                    crr[i] = 0;
                else{
                    crr[i] = 1 ;
                    st = true;
                }
            }else{
                crr[i] = 0;
            }
            
        }

        for (int i = 0; i < n; i++) {
            arr[i] = max( brr[i], crr[i]);
        }

        for (int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n' ;


        
    }

    return 0;
}