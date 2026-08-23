/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <cmath>    

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long r , x  ,y  , xx , yy ; 
    cin >>  r >> x >> y >> xx >> yy  ;

    long long dist = (xx-x)*(xx-x) + (yy-y)*(yy-y) ;

    cout << ceil(sqrt(dist)/(2*r ))<< '\n' ;






                
    return 0;
}