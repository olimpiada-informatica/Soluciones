#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	if(k > ((n-2)*(n-3))/2) {
		cout << "NO" << endl;
		return;
	}
	cout << "SI" << endl;
	if(k == 0) {
		for(int i=0; i < n; ++i) {
			cout << i+1 << " ";
		}
		cout << endl;
		return;
	}

	cout << "1 ";
	
	int rn = n;
	int li = 1;
	while(k <= ((rn-3)*(rn-4))/2) {
		rn--;
		cout << li+1 << " ";
		li++;
	}

	int ri = n;
	int invi = k-((rn-3)*(rn-4))/2;

	int cd = (li+ri+2)/2;
	int cu = li+1;

	int ccd = 1;
	int ccu = 1;
	for(int i=0; i < rn-1; ++i) {
		if(i == invi) {
			cd = ri;
			cu = (li+ri+2)/2-1;
			ccd *= -1;
			ccu *= -1;
		}
		if(i%2 == 0) {
			cout << cd << " ";
			cd += ccd;
		}
		else {
			cout << cu << " ";
			cu += ccu;
		}
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