#include<bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int res = 0;
    if (n == 1) {
      res += m/3;
      if (m%3 == 1) res += 3;
      else if (m%3 == 2) res += 2;
    }
    else if (n == 2) {
      res += 2*(m/3);
      res += (m%3)*2;
    }
    else {
      res = m;
    }
    cout << res << endl;
  }
}
