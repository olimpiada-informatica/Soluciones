#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	map<int, int> biy; 
	int it = 1;
	for (int i = 0; i < n; i++) {
		if (biy[a[i]] == 0) biy[a[i]] = it++;
		cout << biy[a[i]] << " ";
	}
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
