/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <set> 

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<long long> arr(n);

        set<long long> ss ;
        ss.insert(0);
    

        bool sus = false;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            
            if(i != 0) {
                if(i & 1)
                    arr[i] = arr[i - 1] - arr[i];
                else
                    arr[i] = arr[i - 1] + arr[i];
            }

//            cout << arr[i] << ' ' ;
            if(ss.count(arr[i])) {
                sus = true;
            }


            ss.insert(arr[i]);


        }   


        if( sus) 
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n' ;

        
        

        
    }

    return 0;
}



// 1 3 2 
// -1 2 0
// -1 1 2


