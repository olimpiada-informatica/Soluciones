#include<bits/stdc++.h>

using namespace std;

int main() {
  int cas;
  cin >> cas;
  while (cas--) {
    int n, m;
    cin >> n >> m;
    vector<int> V(m, 0);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      int cont = 0;
      for (int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        if ((cont + V[j] + x)%2) {
          ++res;
          ++cont;
        }
        V[j] += cont;
      }
    }
    cout << res << endl;
  }
}
