#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
	int T;
	cin >> T;
	while(T--) {
		ll m, n;
		cin >> m >> n;
		vi a(n);
		for(auto &x : a) cin >> x;
		vi s(n+1);
		for(int i=0; i < n; ++i) s[i+1] = s[i]+a[i];
		ll ans = 0;
		ll k = 0;
		for(ll i=0; i < n; ++i) {
			while(k < n && a[k]-a[i] <= m) k++;
			ans += (k-i-1)*(m+a[i])-(s[k]-s[i+1]);
		}
		cout << ans << endl;
	}
	
}