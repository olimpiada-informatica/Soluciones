#include <iostream>
#include <vector>
using namespace std;
#define int long long

void print(int p, int n, int t) {
	cout << t << "\n";
	for (int i = 0; i < n; i++) {
		if (i == p) cout << 2 << " ";
		else cout << 1 << " ";
	}
	cout << "\n";
}

void solve() {
	int n, k, x = 0;
	cin >> n >> k;
	n *= 2;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int i = 0; i < n; ++i) x ^= v[i];
	if (x >= k) {
		print(-1, n, 1);
		return;
	}
	for (int i = 0; i < n; i++) {
		if ((x^v[i]) >= k) {
			print(i, n, 2);
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
