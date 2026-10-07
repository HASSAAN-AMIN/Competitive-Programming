/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include <set>
#include<algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s ;
        
        set<char > ss;
        int ans = 0 ; 
        for (char c : s) {
            ss.insert(c);
            ans += ss.size();
        }
        cout  << ans << '\n' ;


        
    }

    return 0;
}