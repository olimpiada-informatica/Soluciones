#include <bits/stdc++.h>

using namespace std;

const pair<int, int> INV = {-1, -1};
vector<vector<pair<int, int>>> UF;

pair<int, int> F(pair<int, int> p){
	return UF[p.first][p.second] == INV ? p : UF[p.first][p.second] = F(UF[p.first][p.second]);
}

void U(pair<int, int> p1, pair<int, int> p2){
	p1 = F(p1);
	p2 = F(p2);
	if (p1 != p2)
		UF[p1.first][p1.second] = p2;
}

int main(){
	int n, m;
	while (cin >> n >> m){
		vector<vector<int>> v(n, vector<int>(m));
		UF = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m, INV));
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		vector<queue<pair<int, int>>> vQ(62);
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				char c;
				cin >> c;
				if (c == '.' || c == '*' || c == '+') v[i][j] = 0;
				else if (c >= '1' and c <= '9') v[i][j] = c - '1' + 1;
				else if (c >= 'a' and c <= 'z') v[i][j] = c - 'a' + 10;
				else v[i][j] = c - 'A' + 36;
				if (c == '*'){
					x1 = i;
					y1 = j;
				}
				else if (c == '+'){
					x2 = i;
					y2 = j;
				}
				if (v[i][j] > 1)
					vQ[v[i][j]].push({i, j});
			}
		}
		int danger = 61;
		while (danger > 1){
			queue<pair<int, int>>& Q = vQ[danger];
			while (!Q.empty()){
				pair<int, int> it = Q.front();
				Q.pop();
				int& x = it.first;
				int& y = it.second;
				if (danger < v[x][y])
					continue;
				if (x > 0 and v[x-1][y] < danger-1){
					v[x-1][y] = danger-1;
					if (danger > 2)
						vQ[danger-1].push({x-1, y});
				}
				if (y > 0 and v[x][y-1] < danger-1){
					v[x][y-1] = danger-1;
					if (danger > 2)
						vQ[danger-1].push({x, y-1});
				}
				if (x < n-1 and v[x+1][y] < danger-1){
					v[x+1][y] = danger-1;
					if (danger > 2)
						vQ[danger-1].push({x+1, y});
				}
				if (y < m-1 and v[x][y+1] < danger-1){
					v[x][y+1] = danger-1;
					if (danger > 2)
						vQ[danger-1].push({x, y+1});
				}
			}
			danger--;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (v[i][j] > 0)
					continue;
				if (i > 0 and v[i-1][j] == 0)
					U({i, j}, {i-1, j});
				if (j > 0 and v[i][j*1] == 0)
					U({i, j}, {i, j-1});
			}
		}
		cout << (F({x1, y1}) == F({x2, y2}) ? "SI\n" : "NO\n");
	}
}