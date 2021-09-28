#include<bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for(int &x : a) cin >> x;

		sort(a.begin(), a.end());
		bool good = true;
		for(int i=0; i < n; ++i) {
			if(a[i]+a[n-1-i] != a[0]+a[n-1]) {
				good = false;
			}
		}

		cout << (good ? "SI" : "NO") << endl;

	}
}