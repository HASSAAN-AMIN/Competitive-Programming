/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        
        int n , k; 
        cin >> n >> k  ;
        string s ;
        cin >> s ; 

        bool sus = false;
        string t(n , ' '); 

        for (int i = 0; i < k; i++) {
            
            char c = ' ' ;
            for (int j = i; j < n; j+= k) {
                if( s[j] == '?')
                    continue; 
                if( c == 32)    
                    c = s[j];
                else{
                    if( c == s[j])
                        continue;
                    else{
                        sus = true ;
                        break; 
                    }
                }
            }
            t[i] = c  ;
            if(sus)
                break ;
        }

        if(sus) 
            cout << "NO"  << '\n';
        else {
            int o = 0;
            int z = 0;

            for (int i = 0; i < k; i++) {
                if (t[i] == '1')
                    o++;
                else if (t[i] == '0')
                    z++;
            }

            if (o <= k / 2 && z <= k / 2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        

        
    }

    return 0;
} 