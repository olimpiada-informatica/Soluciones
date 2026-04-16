#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve() {
	int n, k; cin >> n >> k;
	vector<int> s(n);
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		if (c == '1') s[i] = 1;
	}
	for (int i = 0; i < 61; i++) {
		if (((1LL << i)&k) != 0) {
			vector<int> t = s;
			for (int j = 0; j < n; j++) 
				t[j] = (s[(j + (1LL <<i))%n] ^ s[(j - (1LL << i)%n + n)%n]);
			s = t;
		}
	}
	for (auto x : s)
		cout << x;
	cout << "\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
