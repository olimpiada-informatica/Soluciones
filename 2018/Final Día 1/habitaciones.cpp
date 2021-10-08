#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi V;
vi P;
vi D;

int dfs1(int x) {
  if (V[x]) return x;
  V[x] = 1;
  return dfs1(P[x]);
}

int dfs2(int x, int k = 0) {
  if (V[x]) return 0;
  V[x] = 1;
  D[x] = k;
  return 1 + dfs2(P[x], k);
}

int dfs3(int x) {
  if (D[x] != -1) return D[x];
  return D[x] = 1 + dfs3(P[x]);
}


int main() {
  int n;
  while (cin >> n) {
    P = vi(n);
    for (int i = 0; i < n; ++i)
      cin >> P[i];
    V = vi(n,0);
    int x = dfs1(0);
    V = vi(n,0);
    D = vi(n,-1);
    int k = dfs2(x);
    V = vi(n,0);
    dfs2(x,k);
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << dfs3(i);
    }
    cout << endl;
  }
}
