/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

// bool can( long long  l , long long  n , long long  m  ){

//     if( l%n == 0){
//         if(l/n <= m)
//             return true;
//     }
//     return false;

// }


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        long long  n , m ;
        cin >> n >> m ;   
        int nn=  n;     

        // how can we increase 0s?
        // 10s
        // 520 
        // 5200
        // 2600

        // 10050 12345
        // 124017000
        // 120600000

        // 5 43
        // max could be  215 
        // check for each rounded
        // 210
        // 200
        // is acheivable(num)
        //   -> 200/5  -> is int -> <= m

        // long long  ans = 0;


        // string s = to_string(ans);
        // string t = s;


        // long long  sz = s.size() ;
        // char c  =  s[0];
        // s = c ;
        // for (int i = 0; i < sz-1; i++) {
        //     s += '0' ;
        // }

        // // cout << s << '\n' ;

        // // cout << t << '\n' ;
        // // cout << "---\n" ;

        // vector<string> perms;

        // for(int b = 1; b < (1 << sz); b++) {

        //     string cur = t;

        //     for(int i = 0; i < sz; i++) {
        //         if(b & (1 << i))
        //             cur[i] = t[i];
        //         else
        //             cur[i] = '0' ;
        //     }

        //     if( stoll(cur) <= ans){
        //         perms.push_back(cur);
        //         //cout << cur << '\n';
        //     }

            
        // }
        

        // for (int i = 0; i < perms.size(); i++) {
        //     cout << perms[i] << '\n';
        // }

        // for(string &p : perms) {

        //     long long l = stoll(p);

        //     if(can(l, n, m)) {
        //         ans = max(ans , l);
        //         break;
        //     }
        // }
        
        // cout << ans << '\n';
        
        // nvm ts wasnt that hard
        int a = 0 ;
        int b = 0 ;
        long long l = 1 ;
        while(n && n%2 == 0){
            a++;
            n /= 2;
        }
        while(n && n%5 == 0){
            b++;
            n /= 5;
        }
        while( a < b && l*2 <= m){
            l*= 2;
            a++;
        }
        while( a > b && l*5 <= m){
            l*= 5;
            b++;
        }        
        while( l*10 <= m)
            l*=10;
        if( l == 1)
            cout << nn*m << '\n';
        else
            cout << nn * l * (m/l) << '\n' ;

    }

    return 0;
}


// 60
// 200
// 65
// 60
// 120600000
// 10
// 100
// 200
// 100
// 7



// 120600000

// 100000000
// 120000000
// 124000000
// 124000000
// 124060000
// 124067000
// 124067200
// 124067250
// 124067250