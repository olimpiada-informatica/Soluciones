#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

int main() {
    int ccc;
    cin >> ccc;
  for (int cas = 0; cas < ccc; ++cas) {
    int n,c;
    cin >> n >> c;
    c /= 15;
    vvi V(n);
    vvi D(n+1, vi(c + 1,0));
    for (int i = 0; i < n; ++i) {
      int k;
      cin >> k;
      V[i] = vi(k);
      for (int j = 0; j < k; ++j) cin >> V[i][j];
      for (int j = 1; j < k; ++j) V[i][j] += V[i][j-1];
    }
    for (int i = n-1; i >= 0; --i) {
      for (int j = 0; j <= c; ++j) {
        D[i][j] = D[i+1][j];
        for (int w = 1; w <= min((int)V[i].size(),j); ++w) {
          D[i][j] = max(D[i][j],D[i+1][j-w] + V[i][w-1]);
        }
        if (j) D[i][j] = max(D[i][j], D[i][j-1]);
      }
    }
    cout << D[0][c] << endl;
  }
}
