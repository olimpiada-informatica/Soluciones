#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> V(m,-1);
		V[0] = 0;
		while (n--) {
			int x,y;
			cin >> x >> y;
			if (V[x] != -1 and (V[y] == -1 or V[y] > V[x] + 1))
				V[y] = V[x] + 1;
		}
		if (V[m-1] == -1) cout << "Imposible" << endl;
		else cout << V[m-1] << endl;
	}
}
