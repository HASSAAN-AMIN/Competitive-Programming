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
        int x;
        cin >> n >> x;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        vector<int> divs;
        for (int i = 2; i * i <= x; i++) {
            if( i*i == x)
                divs.push_back(i); 
            else if (x % i == 0) {
                divs.push_back(i);    
                divs.push_back(x / i);
            }
        }
        if (x != 1) 
            divs.push_back(x); 
        
        long long ans = 0;
        for (int i = 0; i < divs.size(); i++) {
            long long cnt =  0;
            for (int j = 0; j < n; j++) {
                if( arr[j] % divs[i] == 0)
                    cnt+= arr[j] ;
            }
            ans = max( ans , cnt ) ;

        }
        
        cout << ans << '\n';
        
    }

    return 0;
}