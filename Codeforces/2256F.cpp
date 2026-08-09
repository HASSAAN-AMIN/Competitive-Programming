/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <queue>


using namespace std;

bool check( int  m , vector<int> arr ){
    priority_queue<long long> pq;
    for (int i = 0; i < arr.size(); i++) {
        pq.push(arr[i] ) ;
    }

    for (int i = m-1 ; i >= 0 && !pq.empty() ;  i--) {
        int p ;
        if( i > 29)
            p = 1 << 30 ;
        else
            p = 1 << i  ;
        
        int x = pq.top() ;
        pq.pop() ;
        if(x > p)   
            pq.push(x-p) ;
    }
    return pq.empty() ;

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

        int l = n;
        int r = n+ 30 ;
        sort(arr.begin(), arr.end());
        while( l < r){
            int m = l + (r-l)/2 ;

            if( check( m , arr ))
                r = m;
            else
                l = m+1;

        }
        cout << l << '\n' ;

    }

    return 0;
}