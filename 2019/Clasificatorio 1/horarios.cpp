#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
	int n, m;
	while (cin >> n >> m) {
		vi D(m + 1, 0);
		vi A(m + 1, -1);
		for (int i = 0; i < n; ++i) {
			int x, y;
			cin >> x >> y;
			A[y] = max(x, A[y]);
		}
		for (int i = 1; i <= m; ++i) 
			D[i] = max(D[i-1], (A[i] == -1 ? 0 : D[A[i]] + 1));
		cout << D[m] << endl;
	}
}
