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


vector <string> M;

vi xmove = {-2, -2, -1, -1, 1, 1, 2, 2};
vi ymove = {1, -1, 2, -2, 2, -2, 1, -1};

int solve(int n, int m, int x, int y){
    queue <vi> Q;
    Q.push({0, x, y});

    vector <vector <bool> > visited (n, vector <bool> (m, false));

    while (not Q.empty()){
        vi aux = Q.front(); Q.pop();

        int d = aux[0], i = aux[1], j = aux[2];

        if (M[i][j] == 'X') continue;
        if (M[i][j] == 'z') return d;

        if (not visited[i][j]){
            visited[i][j] = true;

            for (int k = 0; k < xmove.size(); ++k){
                int ii = i + xmove[k];
                int jj = j + ymove[k];

                if (ii >= 0 and jj >= 0 and ii < n and jj < m) Q.push({d+1, ii, jj});
            }
        }
    }

    return -1;
}

int main (){
    int n, m;
    while (cin >> n >> m){
        M = vector <string> (n);

        for (int i = 0; i < n; ++i) cin >> M[i];

        int x, y;
        cin >> x >> y;

        int ans = solve(n, m, x-1, y-1);
        if (ans == -1) cout << "no" << endl;
        else cout << ans << endl;
    }
}