#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<VVVI> VVVVI;
typedef vector<VVVVI> VVVVVI;
typedef map<char,pair<int,int> > MCP;
typedef vector<string> VS;

string s;
VVVVVI V;
MCP M;
VS keys;

const int INF = 1e9;

void init() {
	keys = VS(3);
	keys[0] = {"QWERTYUIOP'"};
	keys[1] = {"ASDFGHJKL;?"};
	keys[2] = {"ZXCVBNM,.:!"};
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 11; ++j) {
			M[keys[i][j]] = {i,j};
		}
	}
}

int f(int a, int b, int c, int d, int e) {
	if (a == s.size()) return 0;
	if (V[a][b][c][d][e] != -1) return V[a][b][c][d][e];
	int sol = INF;
	int dx = abs(b-M[s[a]].first);
	int dy = abs(c-M[s[a]].second);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 11; ++j) {
			if (abs(d-i) + abs(e-j) <= dx+dy) sol = min(sol,dx+dy+f(a+1,M[s[a]].first,M[s[a]].second,i,j));
		}
	}
	dx = abs(d-M[s[a]].first);
	dy = abs(e-M[s[a]].second);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 11; ++j) {
			if (abs(b-i) + abs(c-j) <= dx+dy) sol = min(sol,dx+dy+f(a+1,i,j,M[s[a]].first,M[s[a]].second));
		}
	}
	return V[a][b][c][d][e] = sol;
}

int main() {
	init();
	int T;
	cin >> T;
	while (T--) {
		s = "";
		char t;
		while (cin >> t and t != '-') s += t;
		V = VVVVVI(s.size(), VVVVI(3,VVVI(11,VVI(3,VI(11,-1)))));
		cout << f(0,1,3,1,6) << endl;
	}
}
