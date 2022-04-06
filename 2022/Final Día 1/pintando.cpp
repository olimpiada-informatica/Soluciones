#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <complex>
#include <sstream>
 
using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef vector <vvii> vvvii;

void build_cycle(int n, int m){
	vvi edges;

	for (int i = 0; i < m; ++i){
		edges.push_back({i, (i + 1) % m});
	}

	for (int i = m; i < n; ++i){
		edges.push_back({i, (i + 1) % m});
		edges.push_back({i, (m + i - 1) % m});
	}

	cout << edges.size() << '\n';
	for (vi& edge: edges) cout << edge[0] << ' ' << edge[1] << '\n';
}



void solve(){
	int n, m;
	cin >> n >> m;

	vi V(m);
	for (int i = 0; i < m; ++i) cin >> V[i];

	vvi dp(m+1, vi(n+1, 0));
	dp[0][0] = 1;

	for (int i = 0; i < m; ++i){
		for (int j = 0; j <= n; ++j){
			if (dp[i][j]){
				dp[i+1][j] = 1;
				if (j + V[i] <= n) dp[i+1][j+V[i]] = 1;
			}
		}
	}

	int maximum = -1;
	for (int i = 1; i <= n and maximum == -1; ++i){
		if (not dp[m][i]) maximum = i;
	}

	if (maximum == -1){
		cout << "SI" << '\n';
		return;
	}

	if (n >= 2 * maximum){
		cout << "NO" << '\n';
		build_cycle(n, maximum * 2);
		return;
	}

	cout << "SI" << '\n';
}


int main() {
	int T;
	cin >> T;

	while(T--) {
		solve();
	}
}
