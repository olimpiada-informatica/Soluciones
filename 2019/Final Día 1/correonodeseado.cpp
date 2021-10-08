#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vi L(n), P(m);
		for (auto& l : L) cin >> l;
		for (auto& p : P) cin >> p;
		sort(L.begin(),L.end());
		sort(P.begin(),P.end());
		ll a = -1;
		ll b = 2e18;
		while (a + 1 < b) {
			ll c = (a+b)/2;
			int j = 0;
			for (auto p : P) {
				int antj = j;
				while (j < n and abs(L[j]-L[antj]) + min(abs(L[j]-p),abs(L[antj]-p)) <= c) ++j;
			}
			if (j == n) b = c;
			else a = c;
		}
		cout << b << endl;
	}
}
