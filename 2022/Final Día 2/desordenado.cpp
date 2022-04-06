#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi shift(const vi& a) {
	int n = a.size();
	vi b = vi(n);
	for(int i=0; i < n; ++i) b[i] = a[(i+1)%n];
	return b;
}

void solve() {
	int n;
	cin >> n;
	vi a(n);
	int ma = 1e9+1;
	for(int i=0; i < n; ++i) {
	 	cin >> a[i];
	 	ma = min(ma, a[i]);
	}
	vi b = shift(a);
	if(b[0] == ma) b = shift(b);
	for(int i=0; i < n; ++i) {
		cout << b[i];
		if(i < n-1) cout << " ";
	}
	cout << endl;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}