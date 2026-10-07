/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <stack>
#include <numeric>
#include <unordered_map>
#include <set>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string s; 
        cin >> s;

        vector<bool > arr( n,  false); 


        stack<int> qq; 


        for (int i = 0; i < n; i++) {

            int x = s[i] - '0' ; 


            if( x == 1)
                qq.push(i) ;
            else if( x == 3){
                arr[i] = true; 
            }else{
                if(qq.empty()){
                    arr[i] = true;
                }else{
                    arr[qq.top()] = true ;
                    qq.pop() ;
                }
            }
        }
        int cnt  = 0 ;
        for (int i = 0; i < n; i++) {
            if( arr[i] == 0)
                cnt++; 
        }
        cout << cnt << '\n' ;
        for (int i = 0; i < n; i++) {
            if( arr[i] == 0)
                cout << i+1 << ' ';
        }
        cout << '\n' ;

        
    }

    return 0;
}