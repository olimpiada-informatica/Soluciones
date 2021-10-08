#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

vvi G;
vi P;

int pare(int x) {
  if (P[x] == -1) return x;
  return P[x] = pare(P[x]);
}

int mx;
int dist;

void dfs(int x, int p = -1, int d = 0) {
  if (d > dist) {
    dist = d;
    mx = x;
  }
  for (int i = 0; i < (int)G[x].size(); ++i) {
    int y = G[x][i];
    if (y == p) continue;
    dfs(y,x,d+1);
  }
}
    

int main() {
  int casos;
  cin >> casos;
  while (casos--) {
    int n;
    cin >> n;
    vpi A(n);
    for (int i = 0; i < n-1; ++i)
      cin >> A[i].first >> A[i].second;
    vi V(n);
    for (int i = 0; i < n; ++i) 
      cin >> V[i];
    P = vi(n,-1);
    for (int i = 0; i < n-1; ++i) {
      int x = A[i].first;
      int y = A[i].second;
      if (V[x] == V[y]) 
        P[pare(x)] = pare(y);
    }
    G = vvi(n);
    for (int i = 0; i < n-1; ++i) {
      int x = pare(A[i].first);
      int y = pare(A[i].second);
      if (V[x] != V[y]) {
        G[x].push_back(y);
        G[y].push_back(x);
      }
    }
    dist = -1;
    dfs(pare(0));
    dist = -1;
    dfs(mx);
    cout << (dist + 1)/2 << endl;
  }
}
