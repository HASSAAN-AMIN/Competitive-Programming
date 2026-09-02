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

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        // what last number does ?
        // 1 -> 2 -> 4 -> 8 -> 6 -> 2  loop
        // 1 2 4 6 8 
        // 3 -> 6 -> 2
        // 5 -> 0 -> 0
        // 7 -> 4  -> 8 -> 6 -> 2 
        // 9 -> 8 -> 6 -> 2

        // 0 doesnt changes
        // either all end in 0s
        // or in 6s  like we can prolly 
        // doest that gurantee ?
        // no like ? 
        // see this 2 18 22
        // ans is no
        // 2 4 8 16 22 
        // 22
        // 18 26 32
        // 24 28
        // hmm

        // should i precompute every number to its final form ? 
        // no
        // maybe ? constraints high
        // but like dealing multiple once  like all psosible
        // but the nums dont looop brotha
        // its infinite goes
        

        // %10 == 0 wont change alright
        // 5 would immediately become 0 like ofc
        // and yeah no one makes 5 so we gotta change them to 0 one
        // and now they are fixed aint going anywhere?
        
        // so can other be now %10 0 ?
        // see up

        // no! they cant
        // so for this its easy 
        // what if theres no  5 and 0 what then ?

        // 1 2 3 4 6 7 8 9
        // odds comes to even and dont escape

        // only evens remans
        // 2 4 6 8 
        // would they repeat or not ?
        // like i mean they would repeate
        // but to the last digit
        // overall ? 
        // bring all of them to same mod
        // like 22 42 62 32
        // now now now
        // like after each cycle they beocme
        // 2 + 4 + 6 + 8 ==  20
        // so they reamins in a 20 order
        // so either they are like
        // 10 30 50 shi
        // or 
        // 20 40 60 shi
        // just check that

        bool fz = false;
        bool sus = true ; 
        for (int i = 0; i < n; i++) {
            if(  arr[i]%10 == 5 || arr[i]%10 == 0){
                fz = true;
                arr[i] += arr[i]%10;
            }
        }
        if( fz ){
            //long long sum = accumulate( arr.begin() , arr.end() , 0ll); 
            if( *min_element(arr.begin(), arr.end()) != *max_element(arr.begin(), arr.end()))
                sus = false;
        }else{

            for (int i = 0; i < n; i++) {
                while( arr[i]%10 != 2 )
                    arr[i] += arr[i]%10;
            }
            bool t1 = false;
            bool t2 = false;
            for (int i = 0; i < n; i++) {
                if( arr[i]%20 == 2) 
                    t1 = true;
                else
                    t2 = true;
            }
            if( t1 && t2)
                sus = false;
        }

        if( sus )
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n'; 


        
    }

    return 0;
}  


// 2 18 22
// 2 26 22
// 2 32 22 