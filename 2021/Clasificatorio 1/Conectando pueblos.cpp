#include <bits/stdc++.h>
using namespace std;

using vb = vector<bool>;
using pii = pair<int,int>; 
using vp = vector<pii>;
using vvp = vector<vp>;

int n, m;
vb vis;
vvp adj;

// DFS sin pasar por aristas con peso > mx
void dfs(int u, int mx) {
    vis[u] = true;
    for (pii p : adj[u]) {
        int v = p.first;
        int w = p.second;
        if (not vis[v] and w <= mx) dfs(v, mx);
    }
}

// Verifica si el subgrafo con aristas 
// de pesos <= mx es conexo
bool connected(int mx) {
    vis = vb(n, false);
    dfs(0, mx);
    for (int i = 0; i < n; ++i) {
        if (not vis[i]) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        adj = vvp(n);
        for (int i = 0; i < m; ++i) {
            int u, v, h;
            cin >> u >> v >> h;
            adj[u].push_back({v, h});
            adj[v].push_back({u, h});
        }    
        int l = 1;
        int r = 1'000'000;
        int ans = 1'000'000;
        while (l <= r) {
            int mid = (l+r)/2;
            if (connected(mid)) {
                ans = mid; // mejor solución hasta ahora
                r = mid-1; // seguimos probando valores < m
            }
            else {
                l = mid+1; // seguimos probando valores > m
            }
        }
        cout << ans << endl;
    }
}