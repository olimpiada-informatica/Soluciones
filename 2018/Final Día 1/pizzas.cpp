#include<bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> D(m, 0);
    for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
        int x;
        cin >> x;
        ++D[x];
      }
    }
    bool si = true;
    for (int i = 0; i < m; ++i) {
      if (D[i]%8) si = false;
    }
    if (si) cout << "SI" << endl;
    else cout << "NO" << endl;
  }
}
