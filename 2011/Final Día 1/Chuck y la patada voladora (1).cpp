#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef long long int ll;

vector <string> V;

int solution(int n, int m, int k){
    vvi dist(n, vi(m, k+1));
    vvi dist2 = dist;

    queue <vi> Q1;
    queue <vi> Q2;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (V[i][j] == 'C') Q1.push({-0, 0, i, j});
        }
    }

    while (not Q1.empty() or not Q2.empty()){
        bool first = true;
        if (Q1.empty()) first = false;
        if (not Q1.empty() and not Q2.empty()){
            if (Q1.front()[0] < Q2.front()[0]) first = false;
        }

        vi aux;
        if (first){
            aux = Q1.front(); Q1.pop();
        }
        else {
            aux = Q2.front(); Q2.pop();
        }

        int d = aux[0];
        int t = aux[1];
        int i = aux[2];
        int j = aux[3];

        if (V[i][j] == 'X') return 20-d;
        if (dist[i][j] <= t) continue;

        dist[i][j] = dist2[i][j] = t;
        for (int ii = -1; ii <= 1; ++ii){
            for (int jj = -1; jj <= 1; ++jj){
                if (ii == 0 and jj == 0) continue;

                int nexti = ii + i, nextj = jj + j;
                if (nexti >= 0 and nexti < n and nextj >= 0 and nextj < m) {
                    if (dist2[nexti][nextj] > t + 1) {
                        dist2[nexti][nextj] = t + 1;
                        Q1.push({d-1, t+1, nexti, nextj});
                    }
                    if (V[i][j] >= 'a' and V[i][j] <= 'z' and dist[nexti][nextj] > 1) Q2.push({d-21, 1, nexti, nextj});
                }
            }
        }
    }

    return -1;
}

int main (){
    int n, m, k;
    cin >> n >> m >> k;

    V = vector <string>(n);
    for (int i = 0; i < n; ++i) cin >> V[i];
    cout << solution(n, m, k) << '\n';
}