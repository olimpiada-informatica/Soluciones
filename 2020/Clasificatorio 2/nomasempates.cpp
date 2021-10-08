#include<bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> V(n);
    for (int i = 0; i < n; ++i) cin >> V[i];
    sort(V.rbegin(), V.rend());
    if (V[k] == V[k-1]) cout << "EMPATE" << endl;
    else cout << "BIEN" << endl;
  }
}
