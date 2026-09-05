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
        int z = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 0) 
                z++;
        }

        // mex a + mex b + mex c >= 2( max mex)
        // if all dist
        // 2 must have 0 ?
        // ofc
        // no if multiple 0 ?
        // if not
        // 0 +0 + anyt    <==> 2 anyth
        // no never
        // so atleaset 2  zeroes must there
        // if no zeroes
        // still  0>=0
        // if more zeroes > 1 
        // 1 1 0 >= 2 ez?



        if (z == 0) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << 'A' ;
            }
            cout << '\n';
            
        }else if (z == 1) {
            cout << "NO\n";
        }else{
            cout << "YES\n";


            string ans;

            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) {
                    if (cnt == 1) {
                        ans+= 'B'; 
                    }else{
                        ans+= 'A';
                    }
                    cnt++;
                } else if (arr[i] == 1) {
                    ans += 'C'; 
                }else{
                    ans += 'A';
                }
            }

            cout << ans << '\n';
        }

    }   

    

    return 0;
}