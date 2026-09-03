/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


// this is a a very nigga question
// which made me so madddddddddddddddd

int get( vector< vector<int>>& pre , int l , int r){
    int ans = 0;

    for (int i = 0; i < 30; i++) {
        int x;
        if (l == 0)
            x = pre[i][r];
        else
            x = pre[i][r]- pre[i][l - 1];

        if (x == r - l + 1)
            ans = (ans | (1 << i));
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector< vector<int> >pre(  30 , vector<int>( n) ) ;

        for (int b = 0 ; b  < 30 ; b++) {
            pre[b][0] = (( 1 << b) & arr[0])!= 0  ;
            for (int i = 1; i < n; i++) {        
                pre[b][i] = pre[b][i-1] + (((1 << b) & arr[i]) != 0);
            }
        }


        int q;
        cin >> q ;
        while(q--){
            int k , l ;
            cin >> l >> k ;
            l-- ;
            // lets do binary search here
            // for r ? 
            // l is fixed
            // r is gonna max  n-1
            int r  = n-1 ;

            if (arr[l] < k) {
                cout << -1 << ' ';
                continue;
            }

            int lo = l ;
            int hi = n - 1;
            int ans = l;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (get(pre, l, mid) >= k) {
                    ans = mid;
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }

            cout << ans + 1 << ' ';

        }
        cout << '\n' ;
    }

    return 0;
}

// 2 -1 5 
// 1 5 2 2 
// 2 6 -1 5 


// -1 3 -1 
// 1 5 2 2  this good
// 1 6 7 5  almost ?