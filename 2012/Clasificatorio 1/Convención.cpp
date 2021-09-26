#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;

vvi G;
vector <bool> visited;

void dfs(int v){
    if (visited[v]) return;
    visited[v] = true;

    for (int i = 0; i < G[v].size(); ++i) dfs(G[v][i]);
}

int main(){
    int n, m;
    cin >> n;

    map <string, int> M;
    int cnt = 0;

    G = vvi(n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        M[s] = cnt++;
    }

    cin >> m;
    for (int i = 0; i < m; ++i){
        string x, y;
        cin >> x >> y;

        int a = M[x], b = M[y];
        G[a].push_back(b);
        G[b].push_back(a);
    }

    visited = vector <bool> (n, false);

    int ans = 0;
    for (int i = 0; i < n; ++i){
        if (not visited[i]){
            ++ans;
            dfs(i);
        }
    }

    cout << ans << endl;
}