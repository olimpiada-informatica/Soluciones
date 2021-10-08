#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    vi V(2*n+1,0);
    for (int i = 1; i <= 2*n; ++i) {
      V[i] = V[i-1] + A[(i-1)%n];
    }
    ll suma = V[n];
    ll res = 0;
    ll acum = 0;
    int ind2 = 0;
    for (int ind1 = 0; ind1 < n; ++ind1) {
      if (ind2 <= ind1) {
        ind2 = ind1;
        acum = 0;
      }
      else {
        ll km = ind2 - ind1 + 1;
        ll kv = V[ind1] - V[ind1-1];
        acum -= kv*km;
      }
      while (2*(V[ind2+1] - V[ind1]) <= suma) {
        ++ind2;
        acum += V[ind2] - V[ind1];
      }
      res += 2*acum;
      if (2*(V[ind2] - V[ind1]) == suma) res -= V[ind2] - V[ind1];
    }
    cout << res << endl;
  }
}
