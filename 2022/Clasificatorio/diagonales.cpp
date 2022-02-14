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
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <vii> vvii;
typedef vector <vvii> vvvii;

vvvii G;
vvi visited;

int mida(int x, int y){
	if (visited[x][y]) return 0;
	visited[x][y] = 1;

	int ans = 1;

	for (ii p : G[x][y]){
		ans += mida(p.first, p.second);
	}

	return ans;
}

void solve() {
	int n, m;
	cin >> n >> m;

	vvi V(n, vi(m));
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j) cin >> V[i][j];
	}

	/* start with \ */
	int ans1 = 0;
	G = vvvii(n+1, vvii(m+1));

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (V[i][j] == 2) continue;

			if ((i+j) & 1){
				G[i][j+1].push_back({i+1, j});
				G[i+1][j].push_back({i, j+1});
				if (V[i][j] == 0) ++ans1;
			}
			else{
				G[i][j].push_back({i+1, j+1});
				G[i+1][j+1].push_back({i, j});
				if (V[i][j] == 1) ++ans1;
			}
		}
	}

	visited = vvi(n+1, vi(m+1, 0));
	bool component = false;

	for (int i = 0; i < n + 1; ++i){
		for (int j = 0; j < m + 1; ++j){
			if (mida(i, j) > 1) {
				if (component) ans1 = -1;
				else component = true;
			}
		}	
	}

	/* start with / */

	int ans2 = 0;
	G = vvvii(n+1, vvii(m+1));

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (V[i][j] == 2) continue;

			if ((i+j) & 1){
				G[i][j].push_back({i+1, j+1});
				G[i+1][j+1].push_back({i, j});
				if (V[i][j] == 1) ++ans2;
			}
			else{
				G[i][j+1].push_back({i+1, j});
				G[i+1][j].push_back({i, j+1});
				if (V[i][j] == 0) ++ans2;
			}
		}
	}

	visited = vvi(n+1, vi(m+1, 0));
	component = false;

	for (int i = 0; i < n + 1; ++i){
		for (int j = 0; j < m + 1; ++j){
			if (mida(i, j) > 1) {
				if (component) ans2 = -1;
				else component = true;
			}
		}	
	}

	if (ans1 == -1) cout << ans2 << '\n';
	else if (ans2 == -1) cout << ans1 << '\n';
	else cout << min(ans1, ans2) << '\n';
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}