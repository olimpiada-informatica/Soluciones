#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll mod = 998244353;

ll pot(ll x, ll e) {
	if (e == 0) return 1;
	ll k = pot(x*x%mod, e/2);
	if (e%2) return k*x%mod;
	return k;
}


const int N = 100000;
const int M = 100;

int main() {
	vi fact(2*N+1,1);
	vi invf(2*N+1,1);
	vi conv(N+1,1);
	for (ll i = 1; i <= 2*N; ++i) { 
		fact[i] = i*fact[i-1]%mod;
		invf[i] = pot(fact[i],mod-2);
	}
	for (int i = 1; i <= N; ++i) {
		conv[i] = fact[2*i]*invf[i]%mod*invf[i]%mod;
	}
	vvi D(M+1, vi(M+1,0));
	D[0][0] = 1;
	for (int j = 1; j <= M; ++j) {
		for (int i = 0; i <= M; ++i) {
			for (int w = 0; w <= i; ++w) {
				D[i][j] = (D[i][j] + D[w][j-1]*conv[i-w]%mod*invf[2*(i-w)])%mod; 
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (k == 1) {
			cout << conv[n] << endl;
		} else if (k == 2) {
			cout << conv[n]*conv[n]%mod << endl;
		} else {
			cout << D[n][k]*fact[2*n]%mod << endl;
		}
	}
}
