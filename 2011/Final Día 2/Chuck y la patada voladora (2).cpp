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

vector <string> M;
vector <string> T;
vvi dist;


void multibfs(int n, int m, int k){
    dist = vvi(n+2, vi(m+2, 1e9));

    queue <vi> Q;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (M[i][j] != '.') Q.push({0, i, j});
        }
    }

    while (not Q.empty()){
        vi aux = Q.front(); Q.pop();

        int d = aux[0];
        int i = aux[1];
        int j = aux[2];

        if (M[i][j] == '#') continue;
        if (dist[i][j] <= d) continue;

        dist[i][j] = d;

        for (int ii = -1; ii <= 1; ++ii){
            for (int jj = -1; jj <= 1; ++jj){
                if (ii == 0 and jj == 0) continue;
                Q.push({d+1, i + ii, j + jj});
            }
        }
    }
}

void bfs(int n, int m, int k){
    queue <ii> Q;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (M[i][j] == 'C') Q.push({i, j});
        }
    }    

    vector <vector <bool> > visited(n+2, vector <bool>(m+2, false));

    bool even = (k % 2 == 0);

    while (not Q.empty()){
        ii aux = Q.front(); Q.pop();

        int i = aux.first;
        int j = aux.second;

        if (dist[i][j] > k/2) continue;
        if (visited[i][j]) continue;

        visited[i][j] = true;
        if (M[i][j] >= 'a' and M[i][j] <= 'z') T[i-1][j-1] = '*'; 

        bool can = not even or dist[i][j] < k/2;

        for (int ii = -1; ii <= 1; ++ii){
            for (int jj = -1; jj <= 1; ++jj){
                if (ii == 0 and jj == 0) continue;

                if (can or dist[i+ii][j+jj] < k/2) Q.push({i + ii, j + jj});
            }
        }
    }   
}

int main () {
    int f, c, k;
    cin >> f >> c >> k;

    M = vector <string> (f+2, string(c+2, '#'));
    for (int i = 1; i <= f; ++i) {
        for (int j = 1; j <= c; ++j) cin >> M[i][j];
    }
    
    T = vector <string> (f, string(c, '.'));
    for (int i = 0; i < f; ++i){
        for (int j = 0; j < c; ++j) T[i][j] = M[i+1][j+1];
    }

    multibfs(f, c, k);
    bfs(f, c, k);

    for (int i = 0; i < f; ++i) cout << T[i] << '\n';
}