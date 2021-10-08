#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

vi num, minnum;
int cont;
int acum;
vvi G;
vpi A;
vi R;

inline int vei(int x, int b) {
  if (A[b].first == x) return A[b].second;
  return A[b].first;
}

inline void actu(int x, int b) {
  ++acum;
  if (A[b].first == x) R[b] = 1;
  else R[b] = -1;
}

void dfs(int x, int p = -1) {
  num[x] = minnum[x] = cont++;
  for (auto id : G[x]) {
    int y = vei(x, id);
    if (y == p) continue;
    if (num[y] == -1) {
      dfs(y, x);
      minnum[x] = min(minnum[x], minnum[y]);
      if (minnum[y] <= num[x]) actu(x, id);
    }
    else {
      minnum[x] = min(minnum[x], num[y]);
      if (num[y] < num[x]) actu(x, id);
    }
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    num = minnum = vi(n, -1);
    cont = acum = 0;
    G = vvi(n);
    A = vpi(m);
    R = vi(m, 0);
    for (int i = 0; i < m; ++i) {
      cin >> A[i].first >> A[i].second;
      G[A[i].first].push_back(i);
      G[A[i].second].push_back(i);
    }
    dfs(0);
    if (acum < k) {
      cout << "NO" << endl;
      continue;
    }
    cout << "SI" << endl;
    for (int i = 0; i < m; ++i) {
      if (!k) break;
      if (R[i] == 1) cout << A[i].first << ' ' << A[i].second << endl;
      if (R[i] == -1) cout << A[i].second << ' ' << A[i].first << endl;
      if (R[i]) --k;
    }
  }
}
