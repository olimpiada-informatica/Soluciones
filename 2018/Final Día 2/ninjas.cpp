#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> adj_list;
vector<int> sources, P, S;
vector<pair<int, int>> dist[2];
int N, node;

void bfs() {
    queue<pair<int, int>> Q;
    dist[0] = dist[1] = vector<pair<int, int>>(N, pair<int, int>(-1, -1)); // D[0] = ninjas, D[1] = guards.
    for (int i = 0; i < (int) sources.size(); i++) {
        dist[0][sources[i]] = pair<int, int>(0, sources[i]); // D[0][room x] = [dist to x from optimal init point, room person came from to get to room x]
        Q.push(pair<int, int>(sources[i], sources[i]));
    }
    int x, fr, dis, v;
    while(!Q.empty()) {
        x = Q.front().first; // room person arrived to
        fr = Q.front().second; // room where person came from
        Q.pop();
        dis = dist[0][x].first;
        if (dist[1][x].second == fr) dis = dist[1][x].first;
        for (int i = 0; i < (int) adj_list[x].size(); i++) {
            v = adj_list[x][i];
            if (dist[0][v].first == -1) {
                dist[0][v].first = dis+1;
                dist[0][v].second = fr;
                Q.push(pair<int, int>(v, fr));
            } else if (dist[1][v].second == -1 && dist[0][v].second != fr) {
                dist[1][v].first = dis+1;
                dist[1][v].second = fr;
                Q.push(pair<int, int>(v, fr));
            }
        }
    }
}

int dfs(int u, int pare = -1, int d = 0) {
    int dis = dist[0][u].first;
    if (dist[0][u].second == node)
        dis = dist[1][u].first;
    if (d >= dis) {
        if (P[pare] < P[u]) return N - S[u];
        else return S[pare];
    }
    int v, res = N;
    for (int i = 0; i < (int) adj_list[u].size(); i++) {
        v = adj_list[u][i];
        if (v == pare) continue;
        int cur = dfs(v, u, d+1);
        res = min(res, cur);
    }
    return res;
}

int pfs(int u, int pare = -1, int d = 0) {
    P[u] = d;
    S[u] = 1;
    int v;
    for (int i = 0; i < (int) adj_list[u].size(); i++) {
        v = adj_list[u][i];
        if (v == pare) continue;
        S[u] += pfs(v, u, d+1);
    }
    return S[u];
}

int main() {
    int T, a, b;
    cin >> T;
    while(T--) {
        cin >> N;
        adj_list = vector<vector<int>>(N);
        P = S = vector<int>(N);
        sources.clear();
        for (int i = 0; i < N-1; i++) {
            cin >> a >> b;
            adj_list[a].push_back(b);
            adj_list[b].push_back(a);
        }
        for (int i = 0; i < N; i++)
            if (adj_list[i].size() == 1)
                sources.push_back(i);
        pfs(0);
        bfs();
        int res = 0;
        for (int i = 0; i < (int) sources.size(); i++) {
            node = sources[i];
            res = max(res, dfs(node));
        }
        cout << res << "\n";
    }
    return 0;
}
