#include<bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

struct DSU {
    vi v;
    DSU(int n) {
        v = vi(n);
        for (int i=0; i < n; ++i) v[i] = i;
    }

    int find_set(int x) {
        if (v[x] == x) return x;
        return v[x] = find_set(v[x]);
    }

    void unite(int x, int y) {
        v[find_set(x)] = find_set(y);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vvi al(n);
    for (int i=0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        al[max(u, v)].push_back(min(u, v));
    }

    DSU dsu(n);
    
    int nc = 1;
    vi col(n);
    col[0] = 0;
    for (int u=1; u < n; ++u) {
        map<int, int> cmap;
        vector<set<int>> color_representatives;
        set<int> color_cycles;
        for (int v : al[u]) {
            if (cmap.find(col[v]) == cmap.end()) {
                cmap[col[v]] = color_representatives.size();
                color_representatives.emplace_back();
            }
            if (color_representatives[cmap[col[v]]].count(dsu.find_set(v))) {
                color_cycles.insert(col[v]);
            }
            else {
                color_representatives[cmap[col[v]]].insert(dsu.find_set(v));
            }
        } 
        int c;
        for (c = 0; c < nc; ++c) {
            if (!color_cycles.count(c)) break;
        }
        col[u] = c;
        if (c == nc) nc++;
        for (int v : al[u]) {
            if (col[v] == c) {
                dsu.unite(u, v);
            }
        }

    }

    cout << "SI " << nc << endl;
    for (int i=0; i < n; ++i) {
        if (i) cout << " ";
        cout << col[i]+1;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
       solve();
    }
}
