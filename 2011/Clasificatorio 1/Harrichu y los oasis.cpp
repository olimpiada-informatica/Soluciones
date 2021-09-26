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
vvi dist;

void multibfs(int n, int m, int k){
    dist = vvi(n+2, vi(m+2, 1e9));

    queue <vi> Q;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (M[i][j] == 'O' or M[i][j] == 'H') Q.push({0, i, j});
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
        Q.push({d+1, i-1, j});
        Q.push({d+1, i+1, j});
        Q.push({d+1, i, j-1});
        Q.push({d+1, i, j+1});
    }
}

void bfs(int n, int m, int k){
    int tesoros = 0;
    int oasis = 1;

    queue <ii> Q;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (M[i][j] == 'H') Q.push({i, j});
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
        if (M[i][j] == 'T') ++tesoros;
        if (M[i][j] == 'O') ++oasis;

        if (not even or dist[i][j] < k/2 or dist[i-1][j] < k/2) Q.push({i-1, j});
        if (not even or dist[i][j] < k/2 or dist[i+1][j] < k/2) Q.push({i+1, j});
        if (not even or dist[i][j] < k/2 or dist[i][j-1] < k/2) Q.push({i, j-1});
        if (not even or dist[i][j] < k/2 or dist[i][j+1] < k/2) Q.push({i, j+1});
    }

    cout << "tesoros: " << tesoros << endl;
    cout << "oasis: " << oasis << endl;   
}

int main () {
    int f, c, k;
    cin >> f >> c >> k;

    M = vector <string> (f+2, string(c+2, '#'));
    for (int i = 1; i <= f; ++i) {
        for (int j = 1; j <= c; ++j) cin >> M[i][j];
    }

    multibfs(f, c, k);
    bfs(f, c, k);
}