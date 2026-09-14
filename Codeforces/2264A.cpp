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
        
        bool sus = true;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }   

        int prev = n + 1;
        bool nah = true;

        for (int i = 0; i < n; i++) {

            if (arr[i] == i + 1)
                continue;

            if (prev < arr[i]) {
                nah = false;
            }

            prev = arr[i];
        }

        if (nah)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}   