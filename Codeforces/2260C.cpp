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
        int x , y ;
        cin >> x >> y;

        // x dec
        // y inc

        // bruteforce o(x)

        // ik tle
        // int ops = 0;
        // int ans = -1;
        // int cnt = 0 ;
        // while(x >=0){
        //     if( (x ^ y ) > ans){
        //         ans = x^y;
        //         ops = cnt;
        //     }
        //     cnt++;
        //     x--; 
        //     y++;   
        // }
        // cout << ans << ' ' << ops << '\n';


        // xor when max ?
        // when max bit difference
        // when max bit difference ?
        // if y wont increse
        // ez then

        //  max bit differece ?
        // what bit difference they undergo btw ?

        // let
        //    10001010
        //    10110111
        //xor:00111101
        // dec first , inc sec
        //    10001001
        //    10111000
        //xor:00110001

        // 00111101
        // 00110001
        // prev was good 
        // is that alwasy true?
        // noooo!

        // ( x - smth) ^ ( y + smth) 
        // (x-k)^(y+k)  
        // we know 
        //   a ^ b = a + b - 2( a & b )
        // so
        // (x-k)^(y+k)  = x-k+y+k -2( (x-k)&(y+k))
        //              = x + y - 2(  smth)
        // to maximize this  the and part is  0
        // so like that
        // so ans is  x+y ?
        //
        int ans = x+y;
        // but how do we achevie that xor? 
        // (x-k)^(y+k) = x+y
        // x+y =  x^y + 2 (x & y)
        // x & y == 0 
        // all x y bits are different

        //  so like
        // how how hwo

        // build that shi
        //  let z = x - k
        // build z
        // add bits of sum to z
        // if the x allows it
        // that is that only if z <= x

        // reverse bits start 

        int z = 0 ;
        
        for (int i = 31 ; i >= 0 ; i--) {
            // ahn now 
            if(  ans & ( 1 << i) ){
                // if sum has this bit
                
                // now we would love to check
                // if z allows it or not right?

                if( z + (1 << i) <= x){
                    z += (1 << i);
                }
            }       

        }
        cout << ans << ' ' << x - z << '\n';



    }

    return 0;
}