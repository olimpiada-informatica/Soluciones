#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long int ll;

vector<vector<pair<ll, ll>>> adj;
vector<ll> dist, cost;
ll plusINF = 2e18;
int N;

void Dijkstra() {
    dist.assign(N, plusINF);
    cost.assign(N, plusINF);
    dist[0] = 0;
    cost[0] = 0;
    priority_queue<vector<ll>, vector<vector<ll> >, greater<vector<ll> > > pq;
    pq.push({0, 0, 0}); // dist, cost, v;
    vector<ll> cur;
    pair <ll, ll> cur_v;
    ll dis, cos, ed_v, u, v;
    while(!pq.empty()) {
        cur = pq.top();
        pq.pop();
        dis = cur[0];
        cos = cur[1];
        u = cur[2];
        // if (dis+cos > dist[u]+cost[u]) continue;
        for (int i = 0; i < (int) adj[u].size(); i++) {
            cur_v = adj[u][i];
            v = cur_v.first;
            ed_v = cur_v.second;
            if (cos + ed_v + dis < cost[v]) {
                cost[v] = cos + ed_v +dis;
                dist[v] = dis+ed_v;
                pq.push({dist[v], cost[v], v});
            } else if (dis + ed_v < dist[v]) {
                //cost[v] = cos + ed_v +dis;
                pq.push({dis + ed_v, cos + ed_v +dis, v});
            }
        }
    }
    for (int D = 1; D < N; D++) {
        if (cost[D] == plusINF) cout << "-1 ";
        else cout << cost[D] << " ";
    }
    cout << "\n";
}

int main() {
    int T, M;
    ll C, A, B;
    vector<pair<ll, ll>> empt;
    cin >> T;
    while(T--) {
        cin >> N >> M;
        adj.assign(N, empt);
        while(M--) {
            cin >> A >> B >> C;
            adj[A].push_back({B, C});
        }
        Dijkstra();
    }
    return 0;
}
