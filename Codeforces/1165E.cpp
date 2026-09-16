/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while(t--){
        int n;
        cin >> n;


        // nums all pos
        // minimize for all l and r 
        // shouldnt it be just sorted ascending ?
        // no? like
        // 1 2 3 
        // 1 2 3 
        // gives for whole 1 + 4 + 9 = 14
        // but
        // 1 2 3 
        // 3 2 1 
        // gives 3 + 3 + 4 = 10 ?????????
        // and
        // 1 2 3 
        // 2 1 3 
        // fives 2 + 2+ 9 = 13 ?


        // we must greedy build
        // the more the bigger product outside
        // the less the contribuiton
        // so bigger products outside
        // smaller inside
        // aight

        // how much contribution it gives
        // use the contribuition to the EV method
        // for each l it would occur l times from start and n-l+1 times in end
        // 

        // sum should be
        // a_i * b_i * i * (n- i +1)


        // array a is fixed
        // rest is all constant
        // b_i is variable

        // ez lets just do that

        vector<long long> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> brr(n);
        for (int i = 0; i < n; i++) {
            cin >> brr[i];
        }

        // after that

        for (int i = 0; i < n; i++) {
            arr[i] *= 1ll * (i+1ll) * (n-i); 
        }

        // now we need to attaache b ?
        // which is gonna be multiplied

        //ez
        sort( brr.begin() , brr.end()) ;
        sort( arr.begin() , arr.end() , greater<long long>()) ;

        long long ans  =  0;
        for (int i = 0; i < n; i++) {
            ans +=  arr[i]%MOD * brr[i] ;
            ans =  (ans + MOD )%MOD;
        }
        cout << ans << '\n' ;
    }

    return 0;
}