#include <bits/stdc++.h>
using namespace std;
#define int long long
 
void solve() {
	int n; cin >> n;
	vector<int> v(n), pref(n), dp(n);
	unordered_map<int, int> last;
	for (auto &x : v) cin >> x;
	pref[0] = v[0];
	for (int i = 1; i < n; i++)
		pref[i] = pref[i-1] + (v[i] == 1 ? 1 : -1);	
	
	for (int i = n-1; i >= 0; i--) {
		if (v[i] == 1) {
			int l = (i == 0 ? 0 : pref[i-1]);
			if (last[l] == 0)
				dp[i] = n-i;
			else
				dp[i] = last[l] - i + (last[l] != n-1 ? dp[last[l] + 1] : 0);
		}
		
		if (v[i] == 0) {
			int a = 0, b = 0;
			for (int k = i; k < n; k++) {
				if (b > a+1)
					a++;
				else if (v[k] == 1)
					a++;
				else if (v[k] == 0)
					b++;
				// Pattern 00101010 breaks.
				if (b-a == 0) {
					dp[i] = (k != n-1? dp[k+1] : 0);
					break;
				}
				
				if (b-a == 1 && v[k] == 0 && k > i) {
					dp[i] = dp[k];
					break;
				}
			}
		}
		last[pref[i]] = i;
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans += dp[i];
	cout << ans << "\n";
}
 
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while (T--) 
		solve();
}
