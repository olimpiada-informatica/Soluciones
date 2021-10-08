#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int m, n;
		cin >> m >> n;
		vector<int> V(m,-1);
		while (n--) {
			int a,t;
			cin >> a >> t;
			V[a-1] = max(V[a-1],t);
		}
		sort(V.begin(),V.end());
		int cont = 0;
		int t = 0;
		for (int i = 0; i < m; ++i) {
			if (V[i] >= t) {
				++cont;
				t += cont;
			}
		}
		cout << cont << endl;
	}
}
