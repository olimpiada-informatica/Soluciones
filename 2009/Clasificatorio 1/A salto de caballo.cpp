#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

vector <string> M;

vi xmove = {-2, -2, -1, -1, 1, 1, 2, 2};
vi ymove = {-1, 1, -2, 2, -2, 2, -1, 1};

int bfs (int n, int m){
    queue <vi> Q;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (M[i][j] == 'C') Q.push({0, i, j});
        }
    }

    vector <vector <bool> > visited(n, vector <bool> (m, false));

    while (not Q.empty()){
        vi aux = Q.front(); Q.pop();

        int d = aux[0];
        int i = aux[1];
        int j = aux[2];

        if (M[i][j] == 'X') return d;
        if (M[i][j] == '#') continue;
        if (visited[i][j]) continue;

        visited[i][j] = true;
        for (int k = 0; k < 8; ++k){
            int ii = i + xmove[k];
            int jj = j + ymove[k];

            if (ii >= 0 and jj >= 0 and ii < n and jj < m) Q.push({d+1, ii, jj});
        }
    }

    return -1;
}

int main () {
    int n, m;
    cin >> n >> m;

    M = vector <string> (n);
    for (int i = 0; i < n; ++i) cin >> M[i];

    cout << bfs(n, m) << endl;
}