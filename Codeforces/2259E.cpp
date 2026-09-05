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
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> brr(n+1, 0);
        

        // to check
        // not place possible ?
        // how ?
        // difference array
        // op 
        for(int i = 0 ; i < n; i++){
            if(arr[i] > 0){
                int l = max(0, i - arr[i] + 1);
                int r = min(n-1, i + arr[i] - 1);
                
                brr[l]++;
                brr[r+1]--;
                
            }
        }

        vector<char> no(n, 0);
        // differnece array -> brr
        int cur = 0;
        for( int i = 0 ; i < n ; i++){
            cur += brr[i];
            no[i] = cur > 0;
        }
        

        vector<int> ans(n, 0);
        bool sus = true;

        for(int i = 0 ; i < n ; i++){
            if(arr[i] == 0){
                if(no[i]){ // illegal 
                    sus = false; 
                    break; 
                }
                ans[i] = 1; 
            }
        }

        if(sus){
            for(int i = 0 ; i <n ; i++){
                if(arr[i] > 0){
                    int cnt = 0;
                    // if_possible back front
                    if(i - arr[i] >= 0 && !no[i - arr[i]]){
                        ans[i - arr[i]] = 1; 
                        cnt++; 
                    }
                    if(i + arr[i] < n && !no[i + arr[i]]){ 
                        ans[i + arr[i]] = 1; 
                        cnt++; 
                    }
                    if(cnt == 0){ 
                        sus = false; 
                        break; 
                    }
                }
            }
        }

        if(!sus){
            cout << -1 << '\n';
        } else {
            bool sus2 = false;
            for(int i = 0 ; i < n ; i++) 
                // all ?
                if(ans[i]) { 
                    sus2 = true; 
                    break; 
                }
            if(!sus2) 
                ans[0] = 1; 
            
            string istg;
            for( int i = 0; i < n ; i++) {
                if(ans[i]) 
                    istg += '1';
                else
                    istg += '0'; 
            }
            cout << istg << '\n';
        }

        
    }

    return 0;
}