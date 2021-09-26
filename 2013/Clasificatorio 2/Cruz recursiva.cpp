#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;

vector <string> M;

int power(int n, int x){
    int ans = 1;

    for (int i = 0; i < x; ++i) ans *= n;

    return ans;
}

void draw(int n, int x, int y, int p){
    if (n == 1){
        M[x][1+y] = 'O';
        M[x+1][1+y] = M[x-1][1+y] = '|';
        M[x][1+y-1] = M[x][1+y+1] = '-';
        return;
    }

    p /= 3;

    draw(n-1, x-p, y, p);
    draw(n-1, x+p, y, p);
    draw(n-1, x, y-p, p);
    draw(n-1, x, y+p, p);
    draw(n-1, x, y, p);
}

int main (){
    int n;
    cin >> n;

    int p = power(3, n);

    M = vector <string> (p, string(p + 2, ' '));

    for (int i = 0; i < p; ++i) M[i][0] = M[i][p+1] = '|';

    draw(n, p/2, p/2, p);

    for (int i = 0; i < p; ++i) cout << M[i] << endl;
}