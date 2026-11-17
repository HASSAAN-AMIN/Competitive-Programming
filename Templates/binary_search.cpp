/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(long long mid, vector<long long> &arr, long long k){
    long long need = 0;
    for(long long x : arr){
        if(x < mid)
            need += mid - x;
    }
    return need <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long l = 0;
        long long r = 2e18;
        long long ans = 0;

        while(l <= r){
            long long mid = l + (r - l) / 2;

            if(check(mid, arr, k)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        cout << ans << '\n';

        sort(arr.begin(), arr.end());
        int x;
        cin >> x;
        int pos = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        cout << pos << '\n';
    }

    return 0;
}
