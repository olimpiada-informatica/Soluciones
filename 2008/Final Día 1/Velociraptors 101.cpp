#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

int n, m;

vector <string> M;
vvi dist;

int bfs(){

    queue <vi> Q;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (M[i][j] == 'V') {
                dist[i][j] = 0;
                Q.push({0, i, j});
            }
            if (M[i][j] == '#') dist[i][j] = -1;
        }
    }

    int d = 0;
    while (not Q.empty()){
        vi aux = Q.front(); Q.pop();

        int i = aux[1], j = aux[2];
        d = aux[0];

        if (i > 0 and dist[i-1][j] > d+1){
            dist[i-1][j] = d+1;
            Q.push({d+1, i-1, j});
        }
        if (i < n-1 and dist[i+1][j] > d+1){
            dist[i+1][j] = d+1;
            Q.push({d+1, i+1, j});
        }
        if (j > 0 and dist[i][j-1] > d+1){
            dist[i][j-1] = d+1;
            Q.push({d+1, i, j-1});
        }
        if (j < m-1 and dist[i][j+1] > d+1){
            dist[i][j+1] = d+1;
            Q.push({d+1, i, j+1});
        }
    }

    return d;
}

int main () {
    bool first = true;

    while (cin >> n >> m){
        if (first) first = false;
        else cout << "---" << '\n';

        M = vector <string>(n);
        dist = vvi(n, vi(m, 1e9));

        for (int i = 0; i < n; ++i) cin >> M[i];

        int maximum = bfs();

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (dist[i][j] == maximum) M[i][j] = 'X';
            }
        }


        for (int i = 0; i < n; ++i) cout << M[i] << '\n';
    }
}