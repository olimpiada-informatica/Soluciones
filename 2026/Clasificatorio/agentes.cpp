#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector<vector<int>> adj;
vector<vector<vector<int>>> dp;
const int INF = 1e18;
int n, k; 

vector<int> merge(vector<int> a, vector<int> b) {
	int x = a.size(), y = b.size();
	vector<int> ans(x + y - 1);
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++)
			ans[i+j] = max(ans[i+j], a[i] + b[j]);
	}
	return ans;
}

void dfs(int node, int par) {
	for (auto x : adj[node])
		if (x != par) dfs(x,node);
	
	// first assume we put a 1 in node.
	vector<vector<int>> p;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (auto x : adj[node]) {
		if (x == par) continue;
		vector<int> add(n+1);
		for (int i = 0; i <= n; i++)
			add[i] = max(dp[x][1][i], dp[x][0][i] + 1); // We add an edge if the child is a 0
		while (add.back() < 0) add.pop_back(); // add is never empty
		pq.push({add.size(), p.size()});
		p.push_back(add);
	}
	
	// Case leaf:
	if (pq.empty()) {
		dp[node][0].assign(n+1, -INF);
		dp[node][0][0] = 0;
		dp[node][1].assign(n+1, -INF);
		dp[node][1][1] = 0;
		return;
	}
	
	while (pq.size() != 1) {
		int a = pq.top().second;
		pq.pop();
		int b = pq.top().second;
		pq.pop();
		p[a] = merge(p[a], p[b]);
		pq.push({p[a].size(), a});
	}
	vector<int> a = p[pq.top().second];
	dp[node][1].assign(n+1, -INF);
	for (int i = 0; i < (int)a.size(); i++)
		dp[node][1][i+1] = a[i];
		
		
	// Now assume we put a 0 in node.
	p.clear();
	while (!pq.empty()) pq.pop();
	for (auto x : adj[node]) {
		if (x == par) continue;
		vector<int> add(n+1);
		for (int i = 0; i <= n; i++)
			add[i] = max(dp[x][1][i] + 1, dp[x][0][i]); // We add an edge if the child is a 1
		while (add.back() < 0) add.pop_back(); // add is never empty
		pq.push({add.size(), p.size()});
		p.push_back(add);
	}
	
	while (pq.size() != 1) {
		int a = pq.top().second;
		pq.pop();
		int b = pq.top().second;
		pq.pop();
		p[a] = merge(p[a], p[b]);
		pq.push({p[a].size(), a});
	}
	a = p[pq.top().second];
	dp[node][0].assign(n+1, -INF);
	for (int i = 0; i < (int)a.size(); i++)
		dp[node][0][i] = a[i]; // No need to shift
}

void solve() {
	cin >> n >> k;
	adj.clear();
	adj.resize(n);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	dp = vector<vector<vector<int>>> (n, vector<vector<int>> (2, vector<int> (n+1))); // node, 0/1, k
	dfs(0, -1);
	cout << max(dp[0][0][k], dp[0][1][k]) << "\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
