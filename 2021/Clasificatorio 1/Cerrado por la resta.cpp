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
		bool pos = false;
		bool neg = false;
		int zer = 0;
		for(int i=0; i < n; ++i) {
			if(a[i] > 0) pos = true;
			else if(a[i] < 0) neg = true;
			else zer = 1;
		}
		if(pos && neg) {
			cout << "NO" << endl;
			continue;
		}
		if(neg) {
			for(int i=0; i < n; ++i) a[i] *= -1;
		}
		int minv = 1e9+1;
		for(int i=0; i < n; ++i) {
			if(a[i] != 0) minv = min(minv, a[i]);
		} 
		bool good = true;
		for(int i=0; i < n; ++i) {
			if(a[i]%minv != 0) good = false;
			a[i] /= minv;
			if(a[i] > n-zer) good = false;
		}
		cout << (good ? "SI" : "NO") << endl;
	}
}