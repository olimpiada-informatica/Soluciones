#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;

const ll mod = 1e9 + 7;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    ll c;
    cin >> n >> c;
    vi V(n);
    for (int i = 0; i < n; ++i) cin >> V[i];
    ll res = 1;
    int ind1 = 0;
    int ind2 = n-1;
    while (ind1 < ind2 and min(V[ind1], V[ind2]) == 0) {
      if (V[ind1] == 0) ++ind1;
      else --ind2;
      res = (res*(c-1))%mod;
    }
    if (ind1 == ind2) {
      if (V[ind1] == 0) res = (res*c)%mod;
      cout << res << endl;
      continue;
    }
    vi D(n);
    vi M(n);
    M[0] = 0;
    D[0] = 1;
    M[1] = max(0ll, c-1);
    D[1] = max(0ll, c-2);
    for (int i = 2; i < n; ++i) {
      M[i] = (max(0ll, c-1)*D[i-1])%mod;
      D[i] = (max(0ll, c-2)*D[i-1] + M[i-1])%mod;
    }
    int ind3 = ind1 + 1;
    while (ind3 <= ind2) {
      while (V[ind3] == 0) ++ind3;
      if (V[ind1] == V[ind3]) res = (res*M[ind3-ind1-1])%mod;
      else res = (res*D[ind3-ind1-1])%mod;
      ind1 = ind3;
      ++ind3;
    }
    cout << res << endl;
  }
}
