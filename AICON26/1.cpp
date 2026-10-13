/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool is( int n){
    if( n < 2)
        return false;
    if( n < 4)
        return true;

    if( n %2  == 0 || n%3 == 0){
        return false;
    }
    for (int i = 5; i <= n/i; i+= 6) {
        if( (n % i == 0 )|| ((n%(i+2) )== 0 ))
            return false;
            
    }
    return true;
}


vector<int >  sieve ( int  n){
    vector<bool > arr(n +1  ,true ) ;
    vector<int> primes ;
    arr[0] = false;
    arr[1]  = false ;
    for (int i = 2; i <=  n; i++) {
        if( arr[i]){
            primes.push_back(i) ;
            for (int j = i*i; j <= n; j+= i) {
                arr[j] = false; 
            }
        }
    }
    return primes; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        
        vector<int> arr= sieve( n) ;


        for( auto u : arr){
            cout << u << ' ' ;
        }
        cout << '\n' ;

        
    }

    return 0;
}