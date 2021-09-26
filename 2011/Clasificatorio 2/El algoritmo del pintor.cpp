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
    int n;
    cin >> n;

    char C;
    int x, y;
    cin >> C >> x >> y;

    vector <string> V(n);
    for (int i = 0; i < n; ++i) cin >> V[i];

    queue <vi> Q;
    Q.push({x-1, y-1, V[x-1][y-1]});

    while (not Q.empty()){
        vi aux = Q.front(); Q.pop();

        int i = aux[0];
        int j = aux[1];
        char d = aux[2];

        if (V[i][j] != d) continue;
        V[i][j] = C;

        if (i > 0) Q.push({i-1, j, d});
        if (j > 0) Q.push({i, j-1, d});
        if (i < n-1) Q.push({i+1, j, d});
        if (j < n-1) Q.push({i, j+1, d});
    }

    for (int i = 0; i < n; ++i) cout << V[i] << '\n';
}