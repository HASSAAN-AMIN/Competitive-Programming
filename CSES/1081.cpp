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
        int n;
        cin >> n;

        vector<int> arr(n);

        vector<int>div(1e6+1 ); 

        for (int i = 0; i < n; i++) {
            cin >> arr[i];

            for (int j = 1; 1ll*j*j <= arr[i]; j++) {
                
                if( arr[i]%j==0){
                    if(j*j  !=  arr[i]){
                        div[j]++;
                        div[arr[i]/j]++;
                    }else{
                        div[j]++;
                    }
                }
                
            }

        }


        for (int i = div.size()-1; i >= 0 ; i--) {
            if( div[i] >= 2){
                cout << i << '\n';
                break;
            }   
        }




        
    }

    return 0;
}