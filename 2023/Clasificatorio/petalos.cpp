#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int MIN = 1'000'000'001;
		int respuesta = 0;
		priority_queue<int> pq;

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			MIN = min(MIN, a);
			pq.push(a);
		}

		while (pq.top() != MIN) { //Dividimos las flores más grandes
			int a = pq.top();
			pq.pop();
			a /= 2;
			respuesta++;
			MIN = min(MIN, a);
			pq.push(a);
		}

		cout << respuesta << "\n";
	}
}

