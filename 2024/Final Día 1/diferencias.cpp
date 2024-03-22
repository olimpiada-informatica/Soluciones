#include <iostream>
#include <stack>
using namespace std;

void tablero(int paridad, int n, int m, stack<int>& par, stack<int>& impar) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paridad == 1) {
				cout << impar.top() << " ";
				impar.pop();
			}
			else {
				cout << par.top() << " ";
				par.pop();
			}
			paridad ^= 1;
		}
		cout << endl;
		if (m%2 == 0) paridad ^= 1;
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	
	stack<int> par, impar;
	for (int i = 0; i < n*m; ++i) {
		int a;
		cin >> a;
		
		if (a%2 == 0) {
			par.push(a);
		}
		else {
			impar.push(a);
		}
	}
	
	if (static_cast<int>(par.size()) == n*m/2) { // caso respuesta empezando por impar
		tablero(1, n, m, par, impar);
	}
	else if (static_cast<int>(impar.size()) == n*m/2) { // empezando por par
		tablero(0, n, m, par, impar);
	}
	else { // No hay respuesta
		cout << -1 << "\n";
	}
}

int main() {
    	ios::sync_with_stdio(false);
    	cin.tie(nullptr);
    	
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}
