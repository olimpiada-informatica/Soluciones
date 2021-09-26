#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
 
using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

int main(){
    int n, m;
    cin >> n >> m;

    vector <string> M(n);
    for (int i = 0; i < n; ++i) cin >> M[i];

    int x = n/2, y = m/2;
    int vx = -1, vy = 0;

    while (x >= 0 and y >= 0 and x < n and y < m and M[x][y] == '.'){
        M[x][y] = 'V';

        if (vx == -1){
            if (x > 0 and M[x-1][y] == '.') --x;
            else {
                ++y;
                vx = 0;
                vy = 1;
            }
        }
        else if (vx == 1){
            if (x < n-1 and M[x+1][y] == '.') ++x;
            else {
                --y;
                vx = 0;
                vy = -1;
            }
        }
        else if (vy == -1){
            if (y > 0 and M[x][y-1] == '.') --y;
            else {
                --x;
                vx = -1;
                vy = 0;
            }
        }
        else if (vy == 1){
            if (y < m-1 and M[x][y+1] == '.') ++y;
            else {
                ++x;
                vx = 1;
                vy = 0;
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << M[i] << '\n';
}   