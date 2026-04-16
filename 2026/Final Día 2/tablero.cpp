// n = 100: 2945 ones


#include <bits/stdc++.h>
using namespace std;

int compute(int i, int j, int n, vector<vector<int>>& suf) {
	int k = 0;
	if (i < n-1) k ^= suf[i+1][j];
	if (j < n-1) k ^= suf[i][j+1];
	if (i < n-1 && j < n-1) k ^= suf[i+1][j+1];
	return k;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n = 100;
	vector<vector<int>> v(n, vector<int> (n));
	vector<vector<int>> suf(n, vector<int> (n));
	
	for (int i = 0; i <= n-1; i++)
		v[i][n-1-i] = suf[i][n-1-i] = 1;
	
	for (int i = n-2; i >= 0; i--) {
		int g = 1, b = 0;
		v[i][0] = 1;
		suf[i][0] = 1 + compute(i, 0, n, suf);
		for (int j = 1; j <= i; j++) {
			// v[i-j][j]
			v[i-j][j] = 1;
			suf[i-j][j] = 1 + compute(i-j, j, n, suf);
			int r = compute(i-j, j-1, n, suf);
			if (r != 0) {
				b++;
				v[i-j][j] = 0;
				suf[i-j][j] = 0 + compute(i-j, j, n, suf);
			}
			else g++;
		}
		if (b > g) {
			for (int j = 0; j <= i; j++) {
				// v[i-j][j]
				v[i-j][j] ^= 1;
				suf[i-j][j] = v[i-j][j] + compute(i-j, j, n, suf);
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
	
	
	
}
