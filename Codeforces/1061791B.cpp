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
        int d ;
        cin >> d; 

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort( arr.begin() , arr.end());

        bool sus = false;

        if (n % 2 == 0) {
            for (int i = 0; i < n-1; i+= 2) {
                if(   arr[i+1] - arr[i] > d)
                    sus = true;
            }
        } else {
            sus = true; 
            // for odd skip any ?
            // skip what ? 
            // idk check all small cosntraint
            for (int i = 0; i < n; i++) {

                bool sus2 = false;
                int pre = -1;

                for (int j = 0; j < n; j++) {

                    if (j == i) 
                        continue;   
                    if (pre == -1)
                        pre = j;
                    else{
                        if (arr[j] - arr[pre] > d) 
                            sus2 = true;
                        pre = -1;

                    }
                }

                if (!sus2) {
                    sus = false;
                    break;
                }
            }
        }

        
        if( sus )
            cout << "NO\n";
        else
            cout << "YES\n" ;

        
    }

    return 0;
}