#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	vector<pair<int, int>> cost(n, {n, 0});
	for (int i = 0; i < m; ++i) {
		int u, v, b;
		cin >> u >> v >> b; u--, v--;
		adj[u].push_back({v, b});
		adj[v].push_back({u, b});
	}
	
	priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
	pq.push({{0, 0}, 0});
	while (!pq.empty()) {
		int node = -pq.top().F.S;
		int curr = pq.top().F.F;
		int b = pq.top().S;
		pq.pop();
		
		if (cost[node] != make_pair(n, 0LL))
			continue;
		cost[node] = {curr, b};
			
		for (auto x : adj[node]) {
			pq.push({{curr + (x.F > node), -x.F}, b + x.S});
		}
	}
	
	cout << cost[n-1].F << " " << cost[n-1].S << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while (T--)
		solve();
}
