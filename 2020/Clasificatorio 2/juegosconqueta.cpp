#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vpi;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vpi V(n);
    for (int i = 0; i < n; ++i) cin >> V[i].first;
    for (int i = 0; i < n; ++i) cin >> V[i].second;
    sort(V.begin(), V.end());
    int res = n;
    int cont = 0;
    for (int i = 0; i < n; ++i) {
      if (V[i].second == 1 and cont) {
        --cont;
        res -= 2;
      }
      else if (V[i].second == 2) ++cont;
    }
    cout << res << endl;
  }
}
