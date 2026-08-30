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

    int arr[3] ;
    int brr[3] ;

    int area = 0 ;

    for (int i = 0; i < 3; i++) {
        cin >> arr[i] >> brr[i]; 
        area += arr[i]*brr[i] ;
    }
    int l = 1 ;
    while( l*l < area )
        l++;
    if( l*l != area){
        cout << -1 << '\n';
        return  0  ;
    } 
    vector< vector<char> > grid( l , vector<char>(l)) ;
    bool sus = false;

    for( int m =  0 ; m < 8  ; m++){
        if( m & 1) 
            swap( arr[0] , brr[0]);
        if( m & (1<<1))
            swap( arr[1] , brr[1]);
        if( m & (1<<2))
            swap( arr[2] , brr[2]); 
            
        // possible are
        // a b side c down
        // a c side b down
        // b c side a down
        // a b c stand
        // yeah like standing covered in other rotations?
        // 1  AB
        if( arr[0] + arr[1] == arr[2]){
            if( brr[0] == brr[1]){
                if( brr[0] + brr[2] == arr[0]+ arr[1]){
                    sus = true;
                    
                    for (int i = 0; i < l; i++) {
                        for (int j = 0; j < l; j++) {
                            if( i < brr[0]){
                                if( j < arr[0])
                                    grid[i][j] = 'A';
                                else
                                    grid[i][j] = 'B';
                            }else{
                                grid[i][j] = 'C' ;
                            }
                        }
                    }
                    
                }
            }
        }
        if( sus )
            break;
        // 2  AC
        if( arr[0] + arr[2] == arr[1]){
            if( brr[0] == brr[2]){
                if( brr[0] + brr[1] == arr[0]+ arr[2]){
                    sus = true;
                    
                    for (int i = 0; i < l; i++) {
                        for (int j = 0; j < l; j++) {
                            if( i < brr[0]){
                                if( j < arr[0])
                                    grid[i][j] = 'A';
                                else
                                    grid[i][j] = 'C';
                            }else{
                                grid[i][j] = 'B' ;
                            }
                        }
                    }
                }
            }
        }
        if( sus )
            break;
        // 3  BC
        if( arr[1] + arr[2] == arr[0]){
            if( brr[1] == brr[2]){
                if( brr[0] + brr[2] == arr[1]+ arr[2]){
                    sus = true;
                    
                    for (int i = 0; i < l; i++) {
                        for (int j = 0; j < l; j++) {
                            if( i < brr[1]){
                                if( j < arr[1])
                                    grid[i][j] = 'B';
                                else
                                    grid[i][j] = 'C';
                            }else{
                                grid[i][j] = 'A' ;
                            }
                        }
                    }
                }
            }
        }
        if( sus )
            break;
        // straight up nga

        if( arr[0] == arr[1] && arr[1] == arr[2]){
            if( brr[0]+brr[1]+brr[2] == arr[0]){
                sus = true;
                // if (brr[0] > brr[1]){
                //     swap(brr[0], brr[1]);
                //     swap(arr[0], arr[1]);
                // }
                // if (brr[1] > brr[2]){
                //     swap(brr[1], brr[2]) ; 
                //     swap(arr[1], arr[2]);  
                // }
                // if (brr[0] > brr[1]){
                //     swap(brr[0], brr[1])  ;
                //     swap(arr[0], arr[1]);  
                // }

                for (int i = 0; i < l; i++) {
                    for (int j = 0; j < l; j++) {
                        if( i < brr[0]){
                            grid[i][j] = 'A' ;
                        }else if( i < brr[0] + brr[1] ){
                            grid[i][j] = 'B' ;
                        }else if( i < brr[0] + brr[1]+ brr[2]){
                            grid[i][j] = 'C' ;
                        }
                    }
                }
            }
        }
        if( sus )
            break;
        if( m & 1) 
            swap( arr[0] , brr[0]);
        if( m & (1<<1))
            swap( arr[1] , brr[1]);
        if( m & (1<<2))
            swap( arr[2] , brr[2]); 

    }
    if( sus ){   

        cout << l << '\n';

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                cout << grid[i][j]  ;
            }
            cout << '\n' ;
        }
    }else
        cout << -1 << '\n' ;

    return 0;
}