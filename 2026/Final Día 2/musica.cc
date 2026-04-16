#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD = 1e9 + 7;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	sort(a.begin(), a.end());
	vector<vector<int>> dp(n, vector<int> (n));
	int cnt = 0;
	dp[0][0] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i-1]) cnt = 0;
		else cnt++;
		for (int j = 0; j <= i - cnt; j++)
			dp[i][j] = ((j > 0? dp[i-1][j-1] * (i-(j-1)-cnt) : 0) + dp[i-1][j]*(j+1+cnt)) % MOD;
	}
	cout << dp[n-1][k] << "\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
