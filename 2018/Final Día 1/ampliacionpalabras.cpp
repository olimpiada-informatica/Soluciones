#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<string> vs;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
  ll maxim = 1e18;
  string a;
  ll p, k;
  int cas = 0;
  while (cin >> a) {
    cin >> p >> k;
    vvi G(26, vi(p + 1,1));
    vs S(26);
    for (int i = 0; i < 26; ++i)
      cin >> S[i];
    for (int i = 1; i <= p; ++i) {
      for (int j = 0; j < 26; ++j) {
        G[j][i] = 0;
        for (int w = 0; w < (int)S[j].size(); ++w) {
          int jj = S[j][w] - 'a';
          G[j][i] += G[jj][i-1];
          G[j][i] = min(maxim, G[j][i]);
        }
      }
    }
    while (p) {
      for (int i = 0; i < (int)a.size(); ++i) {
        int j = a[i] -'a';
        if (k <= G[j][p]) {
          a = S[j];
          break;
        }
        k -= G[j][p];
      }
      --p;
    }

    cout << a[k -1] << endl;
  }
}
