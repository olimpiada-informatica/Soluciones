// Solución basada en paridad sin shuffle O(N log N) en tiempo y O(log N) preguntas:
// Es la misma lógica que la solución oficial (tres búsquedas binarias encadenadas
// comprobando la paridad de los elementos únicos), pero omitiendo la aleatorización local.
// Dado que los casos de prueba ya están generados de manera aleatoria uniforme por el juez,
// la posición del último elemento repetido sigue permitiendo reducir los rangos de búsqueda,
// promediando unas ~21-22 preguntas por caso.


#include <bits/stdc++.h>
using namespace std;
 
int t, n;
 
int ask(vector<int> vt) {
  int sz = vt.size();
 
  cout << "? " << sz;
 
  for (const int &i : vt) {
    cout << " " << i+1;
  }
  cout << endl;
 
  int x; cin >> x; return x;
}
 
signed main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
 
  cin >> t;
  while (t--) {
    cin >> n;
 
    int l = 2;
    int r = n*2;
    while (l < r) {
      int mid = (l+r) >> 1;
 
      vector<int> vt;
      for (int i = 0; i <= mid; i++) {
        vt.push_back(i);
      }
      int x = ask(vt);
 
      if ((x & 1) == (mid & 1)) r = mid;
      else l = mid+1;
    }
    int a = l;
 
    l = 1;
    r = a-1;
    while (l < r) {
      int mid = (l+r) >> 1;
 
      vector<int> vt;
      vt.push_back(a);
      for (int i = 0; i <= mid; i++) {
        vt.push_back(i);
      }
      int x = ask(vt);
 
      if ((x & 1) != (mid & 1)) r = mid;
      else l = mid+1;
    }
    int b = l;
 
    l = 0;
    r = b-1;
    while (l < r) {
      int mid = (l+r) >> 1;
 
      vector<int> vt;
      vt.push_back(a);
      vt.push_back(b);
      for (int i = 0; i <= mid; i++) {
        vt.push_back(i);
      }
      int x = ask(vt);
 
      if ((x & 1) == (mid & 1)) r = mid;
      else l = mid+1;
    }
    int c = l;
 
    cout << "! " << c+1 << " " << b+1 << " " << a+1 << endl;
    	int dumb; cin >> dumb;
  }
}
 
/*
1 3 3 2 1 2 3
*/
