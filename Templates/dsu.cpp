/* 
                بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ   
    In the name of Allah, the Most Gracious, the Most Merciful.
*/
#include <iostream>
#include<vector>
#include<algorithm>
#include <numeric>

using namespace std;

vector<int> par, sz;

int find(int x){
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}

bool unite(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b)
        return false;
    if(sz[a] < sz[b])
        swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--){
        int n, m;
        cin >> n >> m;

        par.assign(n, 0);
        sz.assign(n, 1);
        iota(par.begin(), par.end(), 0);

        int comps = n;
        int biggest = 1;

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            if(unite(x, y)){
                comps--;
                biggest = max(biggest, sz[find(x)]);
            }
            cout << comps << ' ' << biggest << '\n';
        }
    }

    return 0;
}
