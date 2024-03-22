#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int test_case() {
	int ans = 0;
	int n;
	cin >> n;
	// Nos guardamos los valores y su indice
	vector<pair<int, int>> a(n), b(n), copya(n);; 
	vector<int> c(n);
	vector<bool> used(n, false);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;	
		a[i].second = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i].first;
		b[i].second = i;
	}
	for (int i = 0; i < n; i++)
		cin >> c[i];
	copya = a;
	// ordenamos todo
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	// Mantenemos estas priority_queues a lo largo de todo el algoritmo
	// Al iterar c_i, am contiene los indices j de los elementos de a que
	// no hemos usado y que a_j <= c_i. bm contiene los indices j 
	// de los elementos de a que no hemos usado y b_j <= c_i
	// ordenaos por a_j.
	// Como mucho introducimos cada elemento de a y b una vez en am y bm
	priority_queue<int> am;
	priority_queue<pair<int, int>> bm;
	int ita = 0, itb = 0;
	for (int i = 0; i < n; i++) {
		bool paired = false; // Si hemos emparejado a c_i
		while (ita < n and a[ita].first <= c[i]) {
			am.push(a[ita].second);
			ita++;
		}
		while (itb < n and b[itb].first <= c[i]) {
			bm.push(make_pair(copya[b[itb].second].first, b[itb].second));
			itb++;
		}
		// quitamos los usados
		while (not am.empty() and used[am.top()]) {
			am.pop();
		}
		while (not bm.empty() and used[bm.top().second]) {
			bm.pop();
		}	
		if (not am.empty()) {
			used[am.top()] = true;
			paired = true;
		}	
		if (not bm.empty() and not paired) {
			used[bm.top().second] = true;
			paired = true;
			ans++; // usar un elemento de bm tiene coste 1
		}	
		if (not paired) {
			return -1;
		}	
	}
	return ans;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		cout << test_case() << "\n";
	}
	return 0;
}
