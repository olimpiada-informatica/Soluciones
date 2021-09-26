#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

vector <string> M;
vvi dist;

int xg, yg, xr, yr;
int n, m;

void bfs(int i, int j){
    queue <vi> Q;
    Q.push({0, i, j});

    while (not Q.empty()){
        vi aux = Q.front(); Q.pop();

        int d = aux[0];
        int x = aux[1];
        int y = aux[2];

        if (dist[x][y] > -1 and dist[x][y] < 1e8) continue;
        dist[x][y] = d;

        if (M[x-1][y] != '#') Q.push({d+1, x-1, y});
        if (M[x+1][y] != '#') Q.push({d+1, x+1, y});
        if (M[x][y-1] != '#') Q.push({d+1, x, y-1});
        if (M[x][y+1] != '#') Q.push({d+1, x, y+1});
    }
}


void raton(){
    dist = vvi(n, vi(m, -1));

    bfs(xg, yg);

    int best = dist[xr][yr];
    best = max(best, dist[xr+1][yr]);
    best = max(best, dist[xr-1][yr]);
    best = max(best, dist[xr][yr+1]);
    best = max(best, dist[xr][yr-1]);

    if (dist[xr][yr+1] == best){
        M[xr][yr] = '.';
        ++yr;
        M[xr][yr] = 'R';
    }
    else if (dist[xr+1][yr] == best){
        M[xr][yr] = '.';
        ++xr;
        M[xr][yr] = 'R';
    }
    else if (dist[xr][yr-1] == best){
        M[xr][yr] = '.';
        --yr;
        M[xr][yr] = 'R';
    }
    else if (dist[xr-1][yr] == best){
        M[xr][yr] = '.';
        --xr;
        M[xr][yr] = 'R';
    }
}

void gato(){
    dist = vvi(n, vi(m, 1e8));

    bfs(xr, yr);

    int best = dist[xg][yg];
    best = min(best, dist[xg+1][yg]);
    best = min(best, dist[xg-1][yg]);
    best = min(best, dist[xg][yg+1]);
    best = min(best, dist[xg][yg-1]);

    if (dist[xg][yg+1] == best){
        M[xg][yg] = '.';
        ++yg;
        M[xg][yg] = 'G';
    }
    else if (dist[xg+1][yg] == best){
        M[xg][yg] = '.';
        ++xg;
        M[xg][yg] = 'G';
    }
    else if (dist[xg][yg-1] == best){
        M[xg][yg] = '.';
        --yg;
        M[xg][yg] = 'G';
    }
    else if (dist[xg-1][yg] == best){
        M[xg][yg] = '.';
        --xg;
        M[xg][yg] = 'G';
    }
}

int main (){
    cin >> n >> m;

    M = vector <string>(n);

    for (int i = 0; i < n; ++i) cin >> M[i];

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (M[i][j] == 'G'){
                xg = i;
                yg = j;
            }
            if (M[i][j] == 'R'){
                xr = i;
                yr = j;
            }
        }
    }

    int p;
    cin >> p;

    for (int i = 0; i < p and (xr != xg or yr != yg); ++i){
        if (i % 2 == 0) raton();
        else gato();

        for (int j = 0; j < n; ++j) cout << M[j] << '\n';
        cout << '\n';
    }
}