#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
const int mod = 1e9+7;
int respuesta = 1;

void dfs(int nodo, vector<vector<pair<int, int>>>& adj, vector<int>& visitado) {
	for (auto x : adj[nodo]) {
		int k = visitado[nodo];
		if (x.S == 0) k = (visitado[nodo]^3);
		if (visitado[x.F] != -1 and visitado[x.F] != k) respuesta = 0;
		if (visitado[x.F] == -1) {
			visitado[x.F] = k;
			dfs(x.F, adj, visitado);
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> criba(100001);
	criba[1] = 1;
	for (int i = 2; i <= 100000; i++) {
		if (criba[i] == 0) {
			criba[i] = i;
			for (int j = i*i; j <= 100000; j += i) criba[j] = i;
		}
	}
	
	int T;
	cin >> T;
	vector<vector<pair<int, int>>> divisor(100001); //Indice, mira hacia arriba o abajo
	vector<int> modified;
	while (T--) {
		respuesta = 1;
		int n;
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			while (criba[a] != a) {
				int k = criba[a];
				while (a%k == 0) {
					a /= k;
				}
				divisor[k].push_back({i, 0});
				modified.push_back(k);
			}
			divisor[ criba[a] ].push_back({i, 0});
			modified.push_back( criba[a] );
			
			while (criba[b] != b) {
				int k = criba[b];
				while (b%k == 0) {
					b /= k;
				}
				divisor[k].push_back({i, 1});
				modified.push_back(k);
			}
			divisor[ criba[b] ].push_back({i, 1});
			modified.push_back( criba[b] );
		}
		
		vector<vector<pair<int, int>>> adj(n);
		for (int p = 0; size_t(p) < modified.size(); p++) {
			int i = modified[p];
			if (i == 1) continue;
			if ((int)(divisor[i].size()) > 2) respuesta = 0;
			else if((int)(divisor[i].size()) == 2) {
				if (divisor[i][0].S == divisor[i][1].S) {
					adj[ divisor[i][0].F ].push_back({divisor[i][1].F, 0}); //coloreados diferentes
					adj[ divisor[i][1].F ].push_back({divisor[i][0].F, 0});
				}
				else {
					adj[ divisor[i][0].F ].push_back({divisor[i][1].F, 1}); //coloreados iguales
					adj[ divisor[i][1].F ].push_back({divisor[i][0].F, 1});
				}
			}
			divisor[i].clear();
		}
		
		vector<int> visitado(n, -1);
		for (int i = 0; i < n; i++) {
			if (visitado[i] == -1) {
				visitado[i] = 1;
				dfs(i, adj, visitado);
				respuesta *= 2;
				respuesta %= mod;
			}
		}
		
		cout << respuesta << "\n";
		
		for (auto x : modified) {
			divisor[x].clear();
		}
		modified.clear();
	}
}

