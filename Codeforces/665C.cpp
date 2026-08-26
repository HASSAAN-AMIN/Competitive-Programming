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

    // int t;
    // cin >> t;
    // while(t--){
    //     int n;
    //     cin >> n;

    //     vector<int> arr(n);

    //     for (int i = 0; i < n; i++) {
    //         cin >> arr[i];
    //     }

        
    // }

    string s; 
    cin >> s;

    int n = s.size() ;
    for (int i = 1; i < n; i++) {
        if(s[i] == s[i-1]){
            if( i == n-1){
                if( s[i-1] == 'b')
                    s[i] = 'c' ;
                else    
                    s[i] = 'b' ;
            }else{
                
                if( s[i-1] == s[i+1]){
                    if( s[i-1] == 'b')
                        s[i] = 'c' ;
                    else    
                        s[i] = 'b' ;
                }else{
                    // aab
                    if (s[i-1] != 'a' && s[i+1] != 'a')
                        s[i] = 'a';
                    else if (s[i-1] != 'b' && s[i+1] != 'b')
                        s[i] = 'b';
                    else
                        s[i] = 'c';
                }

            }
        }
    }

    cout << s << '\n';


    return 0;
}