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
   // cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k ;
        cin >> k ;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> brr = arr;
        sort(brr.begin(), brr.end());


        int l = -1, r = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] != brr[i]) {
                if (l == -1) 
                    l = i;
                r = i;
            }
        }

        
        if (l == -1 || (r - l  < k)) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }

        
    }

    return 0;
}