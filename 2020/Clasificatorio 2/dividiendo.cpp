#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi V(n);
    int mini = 1e9 + 10;
    for (int i = 0; i < n; ++i) {
      cin >> V[i];
      mini = min(mini, V[i]);
    }
    bool res = true;
    for (int i = 0; i < n; ++i) {
      if (V[i]%mini) {
        res = false;
        break;
      }
    }
    if (res) cout << "SI" << endl;
    else cout << "NO" << endl;
  }
}
