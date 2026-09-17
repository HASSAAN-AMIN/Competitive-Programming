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

    int t = 1;
    cin >> t;
    while(t--){
        int c , d ;
        int x; 
        cin >> c >> d >>x ;

        // i have an idea
        //  c.lcm(a , b) + d.gcd(a ,b)  = x
        //  c d and x are known
        //  kinda like 
        //  ax + by = c
        //  so we will find diophantine solutions for x and y
        //  and then like put them in a vector
        //  like those {x , y} pairs
        //  then then then
        //   a*b = lcm * hcf
        //  so like we need to check for those
        //   lcm*hcf we find all divisors
        //  add those in set and then count total


        // solve diophantine eqs
        int a  = c ;
        int b = d ;

        


    }

    return 0;
}