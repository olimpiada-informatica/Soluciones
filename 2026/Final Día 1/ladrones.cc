#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;

int dfs(int node, int par) {
	vector<int> responses;
	for (auto x : adj[node]) {
		if (x == par) continue;
		responses.push_back(dfs(x, node));
	}
	sort(responses.begin(), responses.end(), greater<int>()); // Can be done in O(n) but I wanna check that O(nlogn) passes.
	if (responses.empty()) return 1;
	if (responses.size() == 1) return responses[0];
	return max(responses[0], responses[1] + 1);
}

void solve() {
	int n; cin >> n;
	adj.clear();
	adj.resize(n);
	for (int i = 0; i < n-1; i++) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << dfs(0, -1) << "\n";
}

int main() {
	int T; cin >> T; while (T--) solve();
}
