#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

int n, m;
vector <string> M;
vvvi dir, num, dist, times;
vvi final;

void init(){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			dir[0][i][j] = dir[0][i][j-1] + num[0][i][j-1];
			num[0][i][j] = num[0][i][j-1] + (M[i][j] == 'X');
		}
	}

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			dir[1][i][j] = dir[1][i-1][j] + num[1][i-1][j];
			num[1][i][j] = num[1][i-1][j] + (M[i][j] == 'X');
		}
	}

	for (int i = 0; i <= n; ++i){
		for (int j = m; j >= 1; --j){
			dir[2][i][j] = dir[2][i][j+1] + num[2][i][j+1];
			num[2][i][j] = num[2][i][j+1] + (M[i][j] == 'X');
		}
	}

	for (int i = n; i >= 1; --i){
		for (int j = 1; j <= m; ++j){
			dir[3][i][j] = dir[3][i+1][j] + num[3][i+1][j];
			num[3][i][j] = num[3][i+1][j] + (M[i][j] == 'X');
		}
	}
}

void init_times(){
	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= m; ++j){
			times[0][i][j] = num[0][i][j] + num[1][i][j] - (M[i][j] == 'X');
		}
	}

	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= m; ++j){
			times[1][i][j] = num[2][i][j] + num[3][i][j] - (M[i][j] == 'X');
		}
	}	

	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= m; ++j){
			times[2][i][j] = num[0][i][j] + num[3][i][j] - (M[i][j] == 'X');
		}
	}

	for (int i = 0; i <= n; ++i){
		for (int j = 0; j <= m; ++j){
			times[3][i][j] = num[1][i][j] + num[2][i][j] - (M[i][j] == 'X');
		}
	}
}

void bfs(){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			dist[0][i][j] += dist[0][i-1][j-1] + times[0][i-1][j-1] + dir[0][i][j] + dir[1][i][j];
			times[0][i][j] += times[0][i-1][j-1];
		}
	}

	for (int i = n; i >= 1; --i){
		for (int j = m; j >= 1; --j){
			dist[1][i][j] += dist[1][i+1][j+1] + times[1][i+1][j+1] + dir[2][i][j] + dir[3][i][j];
			times[1][i][j] += times[1][i+1][j+1];
		}
	}

	for (int i = n; i >= 1; --i){
		for (int j = 1; j <= m; ++j){
			dist[2][i][j] += dist[2][i+1][j-1] + times[2][i+1][j-1] + dir[0][i][j] + dir[3][i][j];
			times[2][i][j] += times[2][i+1][j-1];
		}
	}

	for (int i = 1; i <= n; ++i){
		for (int j = m; j >= 1; --j){
			dist[3][i][j] += dist[3][i-1][j+1] + times[3][i-1][j+1] + dir[1][i][j] + dir[2][i][j];
			times[3][i][j] += times[3][i-1][j+1];
		}
	}
}

void sum(){
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			for (int k = 0; k < 4; ++k) {
				final[i][j] += dist[k][i][j];
				final[i][j] -= dir[k][i][j];
			}
		}
	}
}

int solve(int& sol){
	int minimum = 1e9;

	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			if (final[i][j] < minimum){
				minimum = final[i][j];
				sol = 1;
			}
			else if (final[i][j] == minimum) ++sol;
		}
	}

	return minimum;
}



int main () {   

    cin >> n >> m;

    M = vector <string>(n+2, string(m+2, '.'));
    
    for (int i = 1; i <= n; ++i){
    	for (int j = 1; j <= m; ++j) cin >> M[i][j];
    }

   	dir = vvvi(4, vvi(n+2, vi(m+2, 0)));
   	num = dist = times = dir;
   	final = dir[0];

   	init();
   	init_times();
   	bfs();
   	sum();


   	int sol = 0;
   	int minimum = solve(sol);

   	cout << minimum << " " << sol << endl;
}