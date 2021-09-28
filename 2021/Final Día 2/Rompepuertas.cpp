//Simulándolo corréctamente
//Subtask 1: AC
//Subtask 2: AC
//Subtask 3: AC
//Subtask 4: AC

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using vi = vector<int>;

int main() {
	int n, m;
	cin >> n >> m;

	vi puertas(n), concursantes(m);
	for (int& x : puertas) cin >> x;
	for (int& x : concursantes) cin >> x;

	int cact = 0, pact = 0;
	while (pact < n && cact < m) {
		int fres = concursantes[cact];
		while (pact < n && puertas[pact] <= fres) {
			fres -= puertas[pact];
			++pact;
		}
		++cact;
	}

	cout << pact << '\n';

	return 0;
}