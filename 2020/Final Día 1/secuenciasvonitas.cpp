#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
  int t;
  cin >> t;
  int inf = 1e9+10;
  while (t--) {
    int n;
    cin >> n;
    vi V(n);
    for (int i = 0; i < n; ++i) cin >> V[i];
    vi R1(n,1), R2(n,1);
    vi A1(n+1,-1), A2(n+1,-1);
    A1[0] = 0;
    A2[0] = inf;
    for (int i = 0; i < n; ++i) {
      int a = 0;
      int b = n+1;
      while (a+1 < b) {
        int c = (a+b)/2;
        if (A1[c] == -1 or A1[c] > V[i]) b = c;
        else a = c;
      }
      A1[b] = V[i];
      R1[i] += a;
      a = 0;
      b = n+1;
      while (a+1 < b) {
        int c = (a+b)/2;
        if (A2[c] == -1 or A2[c] < V[i]) b = c;
        else a = c;
      }
      A2[b] = V[i];
      R2[i] += a;
    }
    A1 = A2 = vi(n+1, -1);
    A1[0] = 0;
    A2[0] = inf;
    for (int i = n-1; i >= 0; --i) {
      int a = 0;
      int b = n+1;
      while (a+1 < b) {
        int c = (a+b)/2;
        if (A1[c] == -1 or A1[c] > V[i]) b = c;
        else a = c;
      }
      A1[b] = V[i];
      R1[i] += a;
      a = 0;
      b = n+1;
      while (a+1 < b) {
        int c = (a+b)/2;
        if (A2[c] == -1 or A2[c] < V[i]) b = c;
        else a = c;
      }
      A2[b] = V[i];
      R2[i] += a;
    }
    int res = 0;
    for (int i = 0; i < n; ++i) res = max({res, R1[i], R2[i]});
    cout << n - res << endl;
  }
}
