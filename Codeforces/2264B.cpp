/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m ; 
        cin >> m; 


        vector<long long> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        //  neg of sum  prev + now
        //  start priority queue take max to min
        // remove max if small come

        priority_queue<long long> qq;

        long long sum = 0;
        long long ans = -9223372036854775807LL - 1LL;

        for (int i = 0; i < n; i++){

            if(qq.size() == m - 1){
                ans = max(ans, -sum + m * arr[i]);
            }
            if(qq.empty()){
                if(m - 1 > 0){
                    qq.push(arr[i]); 
                    sum += arr[i];
                }
            }else{
                if(qq.size() < m - 1){
                    qq.push(arr[i]);
                    sum += arr[i];
                }else{
                    if(qq.top() > arr[i]){
                        sum -= qq.top();
                        qq.pop();
                        qq.push(arr[i]);
                        sum += arr[i];
                    }
                }
            }
        }
        cout << ans << '\n';
        
    }

    return 0;
}