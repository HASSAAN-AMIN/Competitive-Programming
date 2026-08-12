/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 998244353 ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s; 

        int n = s.size() ;
        int box = 0 ;
        long long ans  = 1 ;
        for (int i = 0; i < s.size(); i++) {
            int j = i+ 1;
            while( j < n && s[i] == s[j]){
                j++;
            }
            ans = (ans * (j - i)) % MOD;
            i = j-1;
            box++;
        }
        for (int i = 1; i <= n - box; i++) {
            ans = (ans * i) % MOD;
        }

        cout << n - box <<  ' '<< ans << '\n' ;
        


        
    }

    return 0;
}