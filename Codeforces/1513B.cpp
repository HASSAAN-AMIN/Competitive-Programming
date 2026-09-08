/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MOD = 1e9 + 7 ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int biggi = 2e5 +1 ;
    vector<long long> fact(biggi );
    fact[0] = fact[1] = 1 ;
    for (int i = 2; i < biggi; i++) {
        fact[i] = (fact[i-1]*i)%MOD; 
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // two zeroes can help
        // what else
        // constraints also pretty

        // hmm
        // let say we find any even if 
        // combintations of left side , combinations of right side
        // no negs ofc
        // if there is one 0 is the ans is 0 ?
        // no ig
        // yeah ofc like all diff bits

        // smth is with bits
        // 

        // check every split?

        // prefix and suffix and ?
        // no
        // differnet perms ? 
        // how to that ?
        // so no
        
        // wait
        // for this and
        // all of the nums should have that bit turned on?
        // how many bits on  for all


        // if there is a solution for turned bit
        // then every one has all that bits
        // so  ? 
        // so any arrangement would work?


        // take toatal and of the array
        // yeah 
        // cnt them
        // fix 1 in start 1 in end
        // and the arrangements
        // we need fact
        // precompute that

        int x = arr[0];
        for (int i = 0; i < n; i++) {
            x &= arr[i];
        }

        int cnt=  0;
        for (int i = 0; i < n; i++) {
            if( arr[i] ==x)
                cnt++;
        }

        cout << ((((1ll*cnt)*(cnt-1ll))%MOD)*(fact[n-2]))%MOD << '\n';

        
    }

    return 0;
}