#include <bits/stdc++.h>
using namespace std;
#define int long long

// Full solution, for each prime keeps a vector of values that are divisible by it, each of this vectors must be sorted.


// Compute primes and greatest prime factor of each value.
const int max_ai = 1'000'000;
vector<int> primes;
vector<int> vis(max_ai + 1);

void init() {
	
	for (int i = 2; i <= max_ai; i++) {
		if (!vis[i]) {
			primes.push_back(i);
			
			for (int j = i; j <= max_ai; j += i)
				vis[j] = i;
		}
	}
}

void solve() {
	int n; cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	
	map<int, vector<int>> all; // For each prime keeps a vector with the values that are divisible by it in order.
	for (int i = 0; i < n; i++) {
		int x = v[i];
		while (x != 1) {
			all[vis[x]].push_back(v[i]);
			x /= vis[x];
		} 
	}
	
	// checks that all vectors are sorted.
	bool ok = true;
	for (auto &[key, t] : all) {
		for (int i = 1; i < (int)t.size(); i++) {
			if (t[i] < t[i-1]) ok = false;
		}
	}
	
	cout << (ok ? "SI" : "NO") << "\n";
	
}


signed main() {

	init();
	
	int t; cin >> t;
	while (t--) solve();
}
