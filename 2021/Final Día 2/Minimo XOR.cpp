#include<bits/stdc++.h>

using namespace std;

vector<unsigned> ans;

const int k = 30;

unsigned ask(unsigned y) {
	cout << "? " << y << endl;
	unsigned x;
	cin >> x;
	return x^y;
}

void rec(unsigned mn, unsigned mx) {

	if(mn == mx) {
		ans.push_back(mn);
		return;
	}

	int cp = 0;
	int c = 0;
	for(int i=0; i < k; ++i) {
		if((mn&(1<<i)) ^ (mx&(1<<i))) {
			cp = mn&(~((1<<(i+1))-1));
			c = i;
		}
	}

	rec(mn, ask(cp|((1<<c)-1)));
	rec(ask(cp|(1<<c)), mx);
	
}

signed main() {
	int n;
	cin >> n;

	int mn = ask(0);
	int mx = ask((1<<k)-1);

	rec(mn, mx);

	cout << "! ";
	for(int i=0; i < n; ++i) {
		cout << ans[i];
		if(i != n-1) cout << " ";
	}
	cout << endl;	
}