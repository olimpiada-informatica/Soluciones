#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

int main(){
    int n, m;
    cin >> n >> m;

    vector <string> M(n, string(m, '.'));
    for (int i = 0; i < n; ++i) M[i][0] = M[i].back() = '*';
    for (int i = 0; i < m; ++i) M[0][i] = M[n-1][i] = '*';

    char c = 'a';
    int x = 1, y = 1;

    while (M[x][y] == '.'){
        M[x][y] = c;
        if (c == 'z') c = 'A';
        else ++c;

        if (M[x][y+1] == '.') ++y;
        else if (M[x+1][y] == '.') ++x;
        else if (M[x][y-1] == '.') --y;
        else --x;
    }

    for (int i = 0; i < n; ++i) cout << M[i] << '\n';
}