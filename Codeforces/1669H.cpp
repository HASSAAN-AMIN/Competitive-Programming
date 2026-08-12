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
        int k ;
        cin >> k ;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int bit = 30 ;

       // while(k){
            while(bit>= 0 && k ){
                int c= 0 ;
                for (int i = 0; i < n; i++) {
                    if( arr[i]&(1 << bit))
                        continue;
                    c++;
                }
                if(k >=  c){
                    for (int i = 0; i < n && k; i++) {
                        if( arr[i]&(1 << bit))
                            continue;
                        arr[i] |= (1 << bit);
                        
                        k--;
                    }
                }

                bit--;
            }
       // }
        int ans= arr[0];
        for (int i = 0; i < n; i++) {
            ans = ans & arr[i]; 
        }
        cout << ans << '\n' ;

        
    }

    return 0;
}