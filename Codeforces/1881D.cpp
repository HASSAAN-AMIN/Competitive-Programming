/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <unordered_map>

using namespace std;



void add(int n , unordered_map<int , int > &mapy){
    for (int i = 2; i*i <= n; i++){
        while(n % i == 0){
            mapy[i]++;
            n /= i;
        }
    }
    if( n > 1)
        mapy[n]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> arr(n); 


        unordered_map<int , int > mapy ; 

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            add( arr[i] , mapy) ;
        }


        bool sus = true;

        for( auto u : mapy){
            if( u.second%n != 0){
                sus = false;
                break;
            }
        }   


        if( sus)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';



        
        

    }

    return 0;
}