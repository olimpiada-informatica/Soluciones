#include <bits/stdc++.h>
using namespace std;
#define int long long

class Segtree {
public:
	long long infinity = 1e18;
	int t; // tamaño
	vector<int> st; // valores

	// Construye el segment tree
	Segtree (vector<int> init) {
		int n = init.size();
		t = get(n);
		st.resize(2*t, infinity);
		for (int i = 0; i < n; i++) st[i+t] = init[i];
		for (int i = t-1; i >= 1; i--) st[i] = min(st[2*i], st[2*i+1]);
	}
	
	// Encuentra la potencia de dos mas pequeña mayor que x
	static int get(int x) {
		int y = 0;
		while ((1LL << y) < x) y++;
		return (1LL << y);
	}
	
	// Actualiza el valor del indice i a x
	void update(int i, int x) {
		i += t;
		st[i] = x;
		while (i > 1) {
			i /= 2;
			st[i] = min(st[2*i], st[2*i+1]);
		}
	}
	
	// Calcula la solucion
	void execute(int x, int n) {
		int i = 0, ans = 0;
		while (query(i, n-1, 0, t-1, 1) <= x) {
			// Buscamos el siguiente minimo
			int nextIdx = find(i, x);
			// Actualizamos los valores
			ans += (nextIdx-i)*x;
			i = nextIdx;
			x %= st[nextIdx+t];
		}
		
		// Valores hasta el final
		ans += (n-i)*x;
		cout << ans << "\n";
	}
	
	// Encuentra el mínimo en el rango [a, b]
	int query(int a, int b, int x, int y, int k) {
		if (y < a or b < x) return infinity;
		if (a <= x and y <= b) return st[k];
		int d = (x+y)/2;
		return min(query(a, b, x, d, 2*k), query(a, b, d+1, y, 2*k+1));
	}
	
	// Encuentra el primer valor menor o igual que x en [i, t]
	int find(int i, int x) {
		// Nodos del segment tree para analizar
		vector<int> nodes;
		getNodes(i, t-1, 0, t-1, 1, nodes); 
		
		for (int j = 0; j < static_cast<int>(nodes.size()); j++) {
			if (st[nodes[j]] <= x) return walking(nodes[j], x);
		}
		
		// Por hipotesis el codigo no llega aqui
		assert(false);
		return -1;
	}
	
	// Dado un intervalo devuelve los nodos que lo definen ordenados
	void getNodes(int a, int b, int x, int y, int k, vector<int>& nodes) {
		if (y < a or b < x) return;
		if (a <= x and y <= b) {
			nodes.push_back(k);
			return;
		}
		int d = (x+y)/2;
		// El orden es importante, analizar primero el hijo de la izq
		getNodes(a, b, x, d, 2*k, nodes);
		getNodes(a, b, d+1, y, 2*k+1, nodes);
	}
	
	// Walikng on segment trees https://usaco.guide/plat/segtree-ext?lang=cpp
	int walking(int k, int x) {
		if (k >= t) return k-t;
		if (st[2*k] <= x) return walking(2*k, x);
		if (st[2*k+1] <= x) return walking(2*k+1, x);

		// Por hipotesis el codigo no llega aqui
		assert(false);
	}
};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int n, q;
		cin >> n >> q;
		vector<int> v(n);
		for (int i = 0; i < n; i++) cin >> v[i];
		Segtree st(v);
		
		while (q--) {
			int type;
			cin >> type;
			if (type == 1) {
				int qi;
				cin >> qi;
				st.execute(qi, n);
			}
			if (type == 2) {
				int idx, x;
				cin >> idx >> x;
				idx--; // 0-index
				st.update(idx, x);
			}
		}
	}
}



