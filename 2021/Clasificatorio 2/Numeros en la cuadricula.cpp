#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

struct op {
	char c;
	int a;
	ll x;
};

int main() {
	int T;
	cin >> T;
	while(T--) {
		ll n, m, q;
		cin >> n >> m >> q;

		vector<op> o(q);
		for(int i=0; i < q; ++i) {
			cin >> o[i].c >> o[i].a >> o[i].x;
			o[i].a--;
		}

		vi f(n);
		vi c(m);

		ll cf = 0;
		ll cc = 0;

		ll ans = 0;

		for(int k=q-1; k > -1; --k) {
			if(o[k].c == 'F') {
				if(!f[o[k].a]) {
					ans += o[k].x*(m-cc);
					cf++;
					f[o[k].a] = 1;
				}
			}
			else {
				if(!c[o[k].a]) {
					ans += o[k].x*(n-cf);
					cc++;
					c[o[k].a] = 1;
				}
			}
		}

		cout << ans << endl;
	}
}