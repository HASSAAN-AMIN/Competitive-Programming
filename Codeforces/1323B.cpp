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
        
        int n ,m ; 
        cin >> n >> m;
        int k ;
        cin >>  k ;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> brr(m);
        for (int i = 0; i < m; i++) {
            cin >> brr[i];
        }

        



    }

    return 0;
}