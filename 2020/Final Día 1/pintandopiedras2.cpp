#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    ll c, p;
    cin >> n >> c >> k >> p;
    assert(n > 1 and k > 1 and n >= k);
    vi V(n+1,0);
    V[0] = 1;
    for (int i = 1; i <= n; ++i) {
      V[i] = c*V[i-1]%p;
      if (i == k) V[i] = (V[i] - c%p + p)%p;
      if (i > k) V[i] = (V[i] - (c-1)*V[i-k]%p + p)%p;
    }
    cout << V[n] << endl;
  }
}
