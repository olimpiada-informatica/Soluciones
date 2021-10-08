#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int main() {
	int n, k;
	while (cin >> n >> k) {
		vi  M(k);
		vpi A(n);
		for (int i = 0; i < n; ++i) {
			cin >> A[i].first;
			A[i].second = i;
		}
		sort(A.begin(), A.end());
		for (auto& m : M) cin >> m;
		vi D(n, 1);
		int res = 1;
		int ind = 0;
		for (int j = 0; j < k; ++j) {
			while (ind < n and A[ind].first <= M[j]) {
				int i = A[ind++].second;
				int sum = 0;
				D[i] = 0;
				if (i > 0) sum += D[i-1];
				if (i < n-1) sum += D[i+1];
				if (sum == 2) ++res;
				else if (sum == 0) --res;
			}
			if (j) cout << ' ';
			cout << res;
		}
		cout << endl;
	}
}
