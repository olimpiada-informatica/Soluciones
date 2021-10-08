#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    ll k;
    cin >> n >> k;
    vi V(n);
    for (int i = 0; i < n; ++i) cin >> V[i];
    sort(V.rbegin(), V.rend());
    for (int i = 0; i < n; ++i) {
      if (k >= V[i]) k -= V[i];
    }
    cout << k << endl;
  }
}
