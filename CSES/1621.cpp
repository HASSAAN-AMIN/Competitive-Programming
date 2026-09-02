/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include  <unordered_set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    unordered_set<int> ss;


    for (int i = 0; i < n; i++) {
        int x;
        cin >>x ;
        ss.insert(x);

    }
    cout << ss.size() <<'\n' ;

    return 0;
}