#include <bits/stdc++.h>
using namespace std;
#define int long long

bool pos(int x, vector<int> v, int n, int k, int m, int r) {
	int total = 0;
	for (int i = 0; i < n; i++) {
		v[i] -= r*x;
	}
	for (int i = 0; i < n; i++) {
		total += max(0LL, (k-v[i] + m+r-1)/(m+r)); // Ceil( (k-v[i])/(m+r))
	}
	return total <= x;
}

bool valid(int x, vector<int>& v, int n, int k, int m, int r) {
	// probamos con x, x-1, ..., x-n+1
	for (int i = 0; i < n; i++) {
		if (pos(max(0LL, x-i), v, n, k, m, r))
			return true;
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; 
	cin >> T;
	while (T--) {
		int n, k, m, r;
		cin >> n >> k >> m >> r;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		int lb = 0, ub = n*k;
		// Si aplicamos k veces la operacion a cada elemento se consigue
		// el objetivo => La cota superior es n*k
		while (lb < ub) {
			int mid = (lb + ub) / 2;
			if (valid(mid, v, n, k, m, r)) ub = mid;
			else lb = mid + 1;
		}
		
		cout << lb << "\n";
	}
	
}
