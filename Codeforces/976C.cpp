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

        int k = n;

        // 1e9 no difference arrys
        // would use coordinate compression type smth else

        vector<pair<pair<int,int>, int>> arr;
        int cnt = 1 ;
        while(k--){
            int l, r;
            cin >> l >> r;
            arr.push_back({{l, r}, cnt});
            cnt++; 
        }
        sort( arr.begin()  , arr.end()  , [](auto a , auto b){ 
            if( a.first.first == b.first.first)
                return a.first.second > b.first.second;
            else
                return a.first.first  < b.first.first; 
        }) ;
    
        int r = arr[0].first.second;
        int y = arr[0].second;

        for(int i = 1; i < n; i++){
            if(arr[i].first.second <= r){
                cout << arr[i].second << " " << y;
                return 0;
            }

            if(arr[i].first.second > r){
                r = arr[i].first.second;
                y = arr[i].second;
            }
        }

        cout << -1 << " " << -1;

        
    }

    return 0;
}