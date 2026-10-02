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
        int n;
        cin >> n;
        int a , b ;
        cin >> a >> b; 

        vector<int> arr(n +1 );
        arr[0]= 0  ;
        for (int i = 1; i < n+ 1 ; i++) {
            cin >> arr[i];
        }

        // binary search for the final positon?
        // cacluate answer for that
        // for some i final
        // always move right 
        // by conquering first
        // and  theen finals
        

        // no ? 
        // lets final be some xf
        // then the a part 
        // the sum gonna be sumation of
        //  a times differencews
        // since everything going smooth
        // and starting from yk  0 
        // so just  a times x final
        
        // for the b part 
        // b times for going to the x final conquer to 
        // its gonna be b times x final
        // and for remaining 
        // for summaiton of all distnaces after x final 
        // to x 
        // like lowk
        //  xf+1 - xf  + xf+2- xf1 ... xend - xf1
        // (summation of all x till end - summation till x final)
        // besides that 
        //  the dist from end to now times x 
        // all multipled by b 
        long long ans  =  ~(1LL << 63);

        vector<long long> pre( n+1) ;
        pre[0]= 0 ;
        for (int i = 1; i < n+1; i++) {
            pre[i] = pre[i-1] +arr[i] ;
        }
        
        for (int i = 0; i < n  +1; i++){
            ans = min(ans, 1LL*(a+b)*arr[i] + 1LL*b*(pre[n]-pre[i] - 1LL*(n-i)*arr[i]));
        }
        cout << ans << '\n';



    }

    return 0;
}