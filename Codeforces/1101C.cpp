/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool cmp(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    
    if (a.first.first == b.first.first) {
        return a.first.second < b.first.second;
    }
    
    return a.first.first < b.first.first;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector < pair<pair<int , int>,int> > segs(n) ; 
        
        for (int i = 0; i < n; i++) {
            segs[i].second = i;
            int l  , r;
            cin >> l >> r;
            segs[i].first.first = l ;
            segs[i].first.second = r; 
        }


        sort( segs.begin() , segs.end()  , cmp) ;

        int hi =  segs[0].first.second  ;

        bool sus  = false;
        // bool sus2 =false ;  

        vector<int> ans( n) ;
        ans[segs[0].second] = 1 ; 
        for (int i = 1 ; i < n ; i++) {
            if(sus){
                // if(segs[i].first.first > hi ){
                //     sus2 = true;
                //     break;
                // }else{
                //     hi = segs[i].first.second;
                // }

                ans[segs[i].second] = 2;
                continue; 
            }
            if( segs[i].first.first <= hi){
                ans[segs[i].second] = 1;
                hi = max(hi  ,segs[i].first.second ) ;
            }else{
                sus = true;

                ans[segs[i].second] = 2;
                hi = max(hi  ,segs[i].first.second ) ;
            }

        }
        if(!sus)
            cout << -1 ;
        else{
            for (int i = 0; i < n; i++) {
                cout << ans[i] << ' ';
            }
        }
        cout << '\n' ;

        
    }

    return 0;
}