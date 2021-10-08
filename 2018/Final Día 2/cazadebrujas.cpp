#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector< vector<int> > f(n), e(n);
		for (int i = 0; i < m; ++i) {
			int a, x, y;
			cin >> a >> x >> y;
			if (a == 1) {
				f[x].push_back(y);
				f[y].push_back(x);
			}
			else {
				e[x].push_back(y);
				e[y].push_back(x);
			}
		}
		int count = 0;
		vector<int> cc(n, -1);
		vector<int> s;
		for (int i = 0; i < n; ++i) {
			if (cc[i] == -1) {
				queue<int> q;
				q.push(i);
				cc[i] = count;
				s.push_back(1);
				while (q.size() > 0) {
					int k = q.front();
					q.pop();
					for (int j = 0; j < f[k].size(); ++j) {
						if (cc[f[k][j]] == -1) {
							++s[count];
							cc[f[k][j]] = count;
							q.push(f[k][j]);
						}
					}
				}
				++count;
			}
		}
		vector< vector<int> > g(count);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < e[i].size(); ++j) {
				g[cc[i]].push_back(cc[e[i][j]]);
			}
		}
		vector<int> b(count, -1);
		vector<int> bc;
		bool ok = true;
		for (int i = 0; ok and i < count; ++i) {
			if (b[i] == -1) {
				int cur = bc.size();
				bc.push_back(s[i]);
				bc.push_back(0);
				queue<int> q;
				q.push(i);
				b[i] = cur;
				while (ok and q.size() > 0) {
					int k = q.front();
					q.pop();
					for (int j = 0; ok and j < g[k].size(); ++j) {
						if (b[g[k][j]] == -1) {
							if (b[k] == cur) b[g[k][j]] = cur + 1;
							else b[g[k][j]] = cur;
							bc[b[g[k][j]]] += s[g[k][j]];
							q.push(g[k][j]);
						}
						else if (b[g[k][j]] == b[k]) ok = false;
					}
				}
			}
		}
		if (not ok) cout << -1 << endl;
		else {
			int res = 0;
			for (int i = 0; i < bc.size(); i += 2) {
				res += min(bc[i], bc[i + 1]);
			}
			cout << res << endl;
		}
	}
}
