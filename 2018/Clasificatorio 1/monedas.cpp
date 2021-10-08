#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (int i = 0; i < n; ++i) cin >> v[i];
		sort(v.begin(), v.end());
		ll m = 0;
		bool ok = true;
		for (int i = 0; ok and i < n; ++i) {
			if (m + 1 < v[i]) ok = false;
			else m += v[i];
		}
		cout << m + 1 << endl;
	}
}
