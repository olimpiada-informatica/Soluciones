#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m;
vvii al;

bool good;
vector<int> visited;

void dfs(int v, ll x, int c) {

	

	if(visited[v] > 0) {
		if(visited[v] != c) good = false;
		return;
	}

	//cerr << v << " " << x << " " << c << endl;

	visited[v] = c;
	for(ii e : al[v]) {
		if(e.second < x) {
			dfs(e.first, x, 3-c);
		}
	}

}


bool bicolorable(ll x) {



	//cerr << "bicolorable(" << x << ")" << endl;

	visited = vector<int>(n, 0);

	good = true;

	for(int i=0; i < n; ++i) {
		if(!visited[i]) dfs(i, x, 1);
	}

	return good;

}

void solve() {
	
	cin >> n >> m;
	al = vvii(n);
	for(int i=0; i < m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		al[u].emplace_back(v, w);
		al[v].emplace_back(u, w);
	}

	ll low = 0;
	ll high = 3000000000;
	while(high > low+1) {
		ll mid = (low+high)/2;
		if(bicolorable(mid)) {
			low = mid;
		}
		else {
			high = mid;
		}
	}

	ll d = low;

	for(int i=0; i < n; ++i) {
		int mj = -1;
		int smj = -1;
		for(int j=0; j < (int)al[i].size(); ++j) {
			if(al[i][j].second < low) {
				if(mj == -1) {
					mj = j;
				}
				else if(al[i][j].second < al[i][mj].second) {
					smj = mj;
					mj = j;
				}
				else if(smj == -1) {
					smj = j;
				}
				else if(al[i][j].second < al[i][smj].second) {
					smj = j;
				}
			}
		}

		if(smj > -1) d = min(d, al[i][mj].second+al[i][smj].second);
	}

	if(d > 2000000000LL) {
		cout << "INF" << endl;
	}
	else {
		cout << d << endl;
	}


}

int main() {
	int T;
	cin >> T;
	while(T--) {
		solve();
	}

}