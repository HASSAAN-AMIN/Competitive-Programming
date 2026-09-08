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

        vector<int> uni(n);

        for (int i = 0; i < n; i++) {
            cin >> uni[i];
        }
        vector<int> skill(n );
        for (int j = 0; j < n; j++) {
            cin >> skill[j];
        }

        vector<vector<long long >> table( n );


        for (int i = 0; i < n; i++) {
            table[uni[i]-1].push_back(skill[i]);
        }

        for (int i = 0; i <n; i++) {
            sort( table[i].begin() , table[i].end() , greater<int>());
        }

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < table[i].size(); j++) {
                table[i][j] += table[i][j-1];
            }
        }

        vector<long long> ans(n, 0);

        for(int i = 0; i < n; i++){

            int sz = table[i].size();

            for(int k = 1; k <= sz; k++){

                int cnt = (sz / k) * k;

                if(cnt > 0){
                    ans[k - 1] += table[i][cnt - 1];
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';



        
    }

    return 0;
}