#include <bits/stdc++.h>

using namespace std;

int p;
vector <int>s;

int find(int val) {
	int r = 0, k = p/2, sum = 0;
	while (k > 0) {
		if (sum + s[r + k] < val) {
			sum+=s[r + k];
			r+=k;
		}
		k/=2;
	}
	return r + 1;
}

void add(int x, int val) {
	while (x <= p) {
		s[x]+=val;
		x+=(x&(-x));
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int>v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		vector <int>ans(n);
		p = 1;
		while (p < n) p*=2;
		s = vector <int>(p+1);
		for (int i = 1; i <= n; ++i) add(i, 1);
		for (int i = n - 1; i >= 0; --i) {
			ans[i] = find(v[i] + 1);
			add(ans[i], -1);
		}
		for (int i = 0; i < n - 1; ++i) cout << ans[i] << " ";
		cout << ans[n - 1] << endl;
	}
}
