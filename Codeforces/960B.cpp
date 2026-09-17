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
    // cin >> t;
    while(t--){
        int n;
        cin >> n;
        int k1 , k2; 
        cin >> k1 >> k2; 

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        vector<int> brr(n);
        for (int i = 0; i < n; i++) {
            cin >> brr[i];
        }

        // idts k1 and k2 are different things
        //  like they both must be added
        // either make them so positive
        // or so negative
        // if already pos then make more pos
        // if already neg make them more neg
        //  ig put a-b in a priority queue
        // with comparator like which cmps the aboslutes
        // and since k1 + k2 is  < 3000
        // just add them ?
        // wait we have to minimize not maximize
        // oh shi
        // for that 
        // still make the a-b array
        // and like converge the largest ones toward zero
        // yeah in a pq ?
        // instead of the yk like custom compartots
        // just store the abs ez shi

        priority_queue<int> pq; 

        for (int i = 0; i < n; i++) {
            arr[i] -= brr[i];
            pq.push(abs(arr[i])) ;
        }

        int k = k1+k2 ;

        while(k--){
            int x = pq.top();
            pq.pop();
            pq.push( abs(x-1)) ; // abs for when 0s only left
        }

        long long ans = 0 ;
        
        while(!pq.empty()){
            ans += 1ll*pq.top()*pq.top() ;
            pq.pop() ;
        }

        cout  << ans << '\n' ;


        
    }

    return 0;
} 