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

        long long sum =  0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i]; 
        }

        vector<int>  req(n);


        for (int i = 0; i < n ; i++) {
            if( 2*arr[i])
        }



        
    }

    return 0;
}