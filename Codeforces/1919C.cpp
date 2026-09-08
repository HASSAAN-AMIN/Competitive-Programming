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
        int a = n+1;
        int b = a;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            // a = max(a , b);
            // b = min(a, b);
            if( a < b)
                swap( a, b);
            if( arr[i] <= b){
                b = arr[i]; 
            }else{
                if( arr[i] <= a){
                    a = arr[i];
                }else{
                    cnt++;
                    b = arr[i];
                }
            }
        }
        cout << cnt << '\n';

        
    }

    return 0;
}