#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;

int main (){
    int f, c;
    cin >> f >> c;

    vector <vector <bool> > V(f, vector <bool> (c, false));
    V[0][0] = true;

    for (int i = 0; i < f; ++i){
        for (int j = 0; j < c; ++j){
            char d;
            cin >> d;

            if (not V[i][j]) continue;
            if (i == f-1) continue;

            int x = d - '0';
            if (j - x >= 0) V[i+1][j-x] = true;
            if (j + x < c) V[i+1][j+x] = true;
        }
    }

    if (V[f-1][c-1]) cout << "YES" << endl;
    else cout << "NO" << endl;
}