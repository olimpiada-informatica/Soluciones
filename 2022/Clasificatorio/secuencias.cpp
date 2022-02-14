#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vi a(n);
		for(int i=0; i < n; ++i) cin >> a[i];
		int pos = 0;
		int neg = 0;
		vi sp(n);
		vi sn(n);

		for(int i=0; i < n-1; ++i) {
			int d= a[i+1]-a[i];
			sp[i+1] = sp[i];
			sn[i+1] = sn[i];
			if(d > 0) {
				pos++;
				sp[i+1]++;
			}
			else if(d < 0) {
				neg++;
				sn[i+1]++;
			}
		}
		int ans = n+1;
		for(int i=0; i < n; ++i) {
			ans = min(ans, min(sn[i]+pos-sp[i], sp[i]+neg-sn[i]));
		}
		cout << ans << endl;



	}
}