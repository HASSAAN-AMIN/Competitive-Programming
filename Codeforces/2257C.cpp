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

        for (int i = 0; i < n- 1 ; i++) {
            int x;
            cin >>x;
        }
        int m ;
        cin >> m ;

        vector<int> arr(m);

        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        cout << m - 1<< '\n' ;
        for (int i = 0 ; i < m-1; i++) {
            cout << arr[i+1 ] << ' ' ;
        }

        cout << '\n';

        
    }

    return 0;
}