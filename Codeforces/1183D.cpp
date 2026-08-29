/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>
#include <set>
#include <climits>


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
        unordered_map<int ,int>  mp ;


        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        vector<int> freq; 
        for( auto u : mp){
            freq.push_back( u.second) ;
        }
        sort(freq.begin()  , freq.end() , greater<int>()) ;
        
        int ans = 0 ;
        int prev = n+1 ;

        for (int i = 0; i < freq.size(); i++) {
            if( min( prev - 1 , freq[i] ) <= 0 )
                break;
            ans += min( prev - 1 , freq[i] ); 
            prev = min( prev - 1 , freq[i] ); 
        }
        cout << ans << '\n' ;
        
    }

    return 0;
}