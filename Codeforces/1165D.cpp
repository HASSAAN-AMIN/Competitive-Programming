/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

// long long lcm(int a, int b){
//     return 1LL * a * b / __gcd(a, b);
// }


vector<long long>div( long long x){
    vector<long long> arr;

    for (long long i = 2 ; i*i <=  x ; i++) {
        if( x%i == 0){
            if( i*i == x){
                arr.push_back(i);
            }else{
            arr.push_back(i) ;
            arr.push_back(x/i) ;    
            }
        }
        
    }
    sort( arr.begin() ,  arr.end()) ;
    return arr ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        

        // isnt it just lcm of all ? 
        // like the least common multiple
        // duhh ?
        // and if it comes out to be one of the given number
        // then it gonna be double of that ?
        // ofc ? 
        // but then  check that all divisors are or arent ?

        // smallest divisor * biggest  = number
        // so just check taht ig ?

        sort( arr.begin() , arr.end()) ;
        long long  x = 1ll*arr[0] * arr[n-1] ;


        vector<long long> divi = div( x) ;

        // cout << "show: divi : \n" ;
        // for( auto x : divi){
        //     cout << x << ' ' ;
        // }
        // cout << '\n'; 
        
        bool sus =false;
        if( divi.size() != n)
            sus = true;

        // 
        if(!sus){
            for (int i = 0; i < n; i++) {
                if( arr[i] != divi[i]){
                    sus = true;
                    break;
                }
            }
        }

        if( sus)
            cout << -1 << '\n';
        else
            cout << x << '\n' ;
    }

    return 0;
}