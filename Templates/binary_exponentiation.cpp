/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

const long long MOD = 1000000007;

long long power(long long a, long long b, long long m = MOD){
    long long res = 1;
    a %= m;
    while(b > 0){
        if(b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long inverse(long long a){
    return power(a, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;

        cout << power(a, b) << '\n';
        cout << inverse(a) << '\n';
    }

    return 0;
}
