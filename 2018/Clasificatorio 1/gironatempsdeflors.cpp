#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, s;
	while (cin >> n >> s) {
		vector< vector<ll> > d(n, vector<ll>(n));
		vector<ll> t(n);
		for (int i = 0; i < n; ++i) cin >> t[i];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) cin >> d[i][j];
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
		vector< vector<ll> > a(1 << n, vector<ll>(n, 0));
		vector< vector<ll> > r(1 << n, vector<ll>(n, s + 1));
		a[1][0] = t[0];
		r[1][0] = 0;
		queue< pair<ll, ll> > q;
		q.push({1, 0});
		while (!q.empty()) {
			pair<ll, ll> k = q.front();
			q.pop();
			ll ta = a[k.first][k.second];
			ll tr = r[k.first][k.second];
			for (int i = 0; i < n; ++i) {
				if (!(k.first&(1 << i)) and i != k.second) {
					ll m = k.first|(1 << i);
					if (tr + d[k.second][i] < r[m][i]) {
						if (r[m][i] == s + 1) {
							q.push({m, i});
							a[m][i] = ta + t[i];
						}
						r[m][i] = tr + d[k.second][i];
					}
				}
			}
		}
		ll best = 0;
		for (int i = 0; i < (1 << n); ++i) best = max(best, a[i][1]);
		cout << best << endl;
	}
}
