/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;  
        int x;
        cin >> x ;
        long long y ;
        cin >> y;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        // one is x 
        // other is x+3

        // who ended with y?

        // what xor does to person
        // xor cannot increase
        // but x and x+3
        // cant do all


        // check all bits of y
        // and check 
        // how can we acheive that?
        // only xor umm
        // 


        // actually
        // we just need to check for alice
        // if not possbile
        // send to BoB 
        // ez

        // check parity of all 32 bits int all array
        // that would tell for only xor but

        // (((3+1)+2)⊕3)⊕4  
        // we can 2d this but constrains too high
        
        
        // guess we need to check from all  like end
        // like biggi bits
        // coz  like they decide to xor or add
        // wait add can affect
        // if this was - it wont  ?
        // yeah 

        // add and xor  do what
        // 0 0 
        // 0 1
        // 1 0 
        // 1 1 
        // parity of any bit remains same
        // but carry
        // so the overall parity is same
        // oh wait x and x+3 have different parity
        
        // sum would be a number
        // now if the sum and y  has same parity
        //      and x is even
        //          so alice is ans
        //      and x is odd 
        //          so bob is
        // reverse


        long long sum = accumulate( arr.begin() , arr.end() , 0ll);

        // sum += y;

        if ((sum + y) % 2 == x % 2) 
            cout << "Alice" << '\n'; 
        else 
            cout << "Bob" << '\n';


    }

    return 0;
}