#include<bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

VVI t;

int solve(int x){
	if (t[x].size() == 0) return 1;
	if (t[x].size() == 1) return 1+solve(t[x][0]);
	return 1+2*min(solve(t[x][0]), solve(t[x][1]));
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		t = VVI(n);
		for (int i = 0; i < n-1; ++i){
			int u, v;
			cin >> u >> v;
			t[u].push_back(v);
		}
		cout << solve(0) << endl;
	}
}
