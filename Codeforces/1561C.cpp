/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool check( int mid , vector<int> &req , vector<vector<int> >& arr){

    int crnt = mid ;

    for (int i = 0; i < arr.size(); i++) {
        if( crnt >= req[i]){
            crnt += arr[i].size() ;
        }else{
            return false;
        }
    }
    return true;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector< vector<int> > arr(n );

        for (int i = 0; i < n; i++) {
            int x  ;
            cin >> x ;
            while(x--){
                int y ;
                cin >> y;
                arr[i].push_back(y); 
            }
        }
        vector<int> req(n) ;

        for (int i = 0; i < n; i++) {
            int idx = 0 ;
            int big = -1;
            for (int j = 0; j < arr[i].size(); j++) {
                
                if( arr[i][j] -j >=  big - idx  ){ // = imp very guess so 
                    big = arr[i][j] ;
                    idx = j ;
                }
            }
            req[i] = big - idx + 1 ;
            arr[i][0] = req[i]; 
        }

        sort(req.begin(), req.end());

        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        // easy lol

        int l = req[0] ;
        int r = req[n-1] ;

        // 0000011111 type binary search
        while(l < r){
            int mid = l + (r-l)/2 ;

            if( check( mid , req , arr )){
                r =mid;
            }else{
                l = mid+ 1;
            }

        }   

        cout << l << '\n';



    }

    return 0;
}