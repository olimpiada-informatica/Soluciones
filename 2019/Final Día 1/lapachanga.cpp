#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<int> vi;

vvpi G;
vi V;

bool dfs(int x, int c, int k) {
	if (V[x] != -1) return (V[x] == c);
	V[x] = c;
	bool res = true;
	for (auto it : G[x]) {
		int y = it.first;
		if (it.second > k) res &= dfs(y,c^1,k);
	}
	return res;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		G = vvpi(n);
		while (m--) {
			int x,y,k;
			cin >> x >> y >> k;
			--x; --y;
			G[x].push_back(pi(y,k));
			G[y].push_back(pi(x,k));
		}
		int a = -1;
		int b = 1e9+10;
		while (a + 1 < b) {
			int c = (a+b)/2;
			bool res = true;
			V = vi(n,-1);
			for (int i = 0; i < n; ++i) {
				if (V[i] == -1) res &= dfs(i, 0,c);
			}
			if (res) b = c;
			else a = c;
		}
		cout << b << endl;
	}
}
