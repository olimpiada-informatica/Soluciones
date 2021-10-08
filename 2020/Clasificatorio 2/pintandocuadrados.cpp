#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;
typedef set<pi> si;

void f(pi x, vpi& V, int i, ll n, ll m, vpi& R) {
  if (i == (int)V.size()) {
    R.push_back(x);
    return;
  }
  ll valtot = 1;
  for (int j = 0; j < V[i].second; ++j) valtot *= V[i].first;
  ll val1 = 1;
  for (int j = 0; j <= V[i].second; ++j) {
    ll val2 = valtot/val1;
    pi y = pi(x.first*val1, x.second*val2);
    if (y.first <= n and y.second <= m) f(y, V, i+1, n, m, R);
    val1 *= V[i].first;
  }
}

int main() {
  int N = (1<<15);
  vi V(N, 0);
  vi P;
  for (ll i = 2; i < N; ++i) {
    if (!V[i]) {
      P.push_back(i);
      for (ll j = i*i; j < N; j += i) V[j] = 1;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    ll n,m,k;
    cin >> n >> m >> k;
    if (n > m) swap(n, m);
    ll val = k;
    vpi F;
    ll tot = 1;
    for (int i = 0; i < (int)P.size(); ++i) {
      if (val%P[i] == 0) {
        ll ac = 1;
        F.push_back(pi(P[i], 0));
        while (val%P[i] == 0) {
          val /= P[i];
          F.back().second++;
          ++ac;
        }
        tot *= ac;
      }
      if (val == 1) break;
    }
    vpi V1, V2;
    int ind = 0;
    ll valf = 1;
    ll sum = 1;
    while (ind < (int)F.size() and (valf*sum)*(valf*sum) < tot) {
      if (V1.size() == 0 or V1.back().first != F[ind].first) {
        valf *= sum;
        sum = 1;
        V1.push_back(pi(F[ind].first, 0));
      }
      ++sum;
      ++V1.back().second;
      --F[ind].second;
      if (F[ind].second == 0) ++ind;
    }
    while (ind < (int)F.size()) {
      if (V2.size() == 0 or V2.back().first != F[ind].first) V2.push_back(pi(F[ind].first, 0));
      ++V2.back().second;
      --F[ind].second;
      if (F[ind].second == 0) ++ind;
    }
    vpi R1, R2;
    f(pi(1,1), V1, 0, n, m, R1);
    f(pi(1,1), V2, 0, n, m, R2);
    sort(R1.begin(), R1.end());
    sort(R2.rbegin(), R2.rend());
    bool pots = false;
    for (int i = 0, j = 0; i < (int)R1.size(); ++i) {
      while (j < (int)R2.size() and R1[i].first*R2[j].first > n) ++j;
      if (j == (int)R2.size()) break;
      if (R1[i].second*R2[j].second <= m) {
        pots = true;
        break;
      }
    }
    if (pots) cout << "SI" << endl;
    else cout << "NO" << endl;
  }
}
