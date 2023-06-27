#include<bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

void solve() {
    int n, m;
    cin >> n >> m;
    vvi al(n);
    for (int i=0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        al[u].push_back(v);
        al[v].push_back(u);
    }
    vi dist(n, -1);
    vi prev(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : al[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u]+1;
                prev[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[n-1] == -1) {
        cout << "0 0" << endl;
    }
    else {
        cout << min(dist[n-1]-1, 3) << " " << dist[n-1]-1 << endl;
        vi path;
        int cu = n-1;
        while(prev[cu] != 0) {
            path.push_back(prev[cu]);
            cu = prev[cu];
        }
        reverse(path.begin(), path.end());
        for (int i=0; i < dist[n-1]-1; ++i) {
            if (i > 0) cout << " ";
            cout << path[i];
        }
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
       solve();
    }
}