#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;

vll T;

void act(int node, int a, int b, int x, int y, ll val) {
  if (b < x or y < a) return;
  if (x <= a and b <= y) {
    T[node] += val;
    return;
  }
  int m = (a+b)/2;
  act(2*node,a,m,x,y,val);
  act(2*node+1,1+m,b,x,y,val);
}

ll que(int node, int a, int b, int x) {
  if (b < x or x < a) return 0;
  if (a == b) return T[node];
  int m = (a+b)/2;
  return T[node] + que(2*node,a,m,x) + que(2*node+1,1+m,b,x);
}

priority_queue<ll>* dfs(int x, ll d, vvi& G, vi& A, vll& N, vll& R, vi& vist) {
  priority_queue<ll>* Q = new priority_queue<ll>();
  Q->push(d-N[x]);
  vist[x] = 1;
  int vv = 0;
  for (auto y : G[x]) {
    if (A[x] == y) ++vv;
    if (vist[y] == 1 or (A[x] == y and vv == 1)) continue;
    auto Q2 = dfs(y, d+1, G, A, N, R, vist);
    if (Q->size() < Q2->size()) swap(Q, Q2);
    while (!Q2->empty()) {
      Q->push(Q2->top());
      Q2->pop();
    }
    delete Q2;
  }
  while (!Q->empty() and Q->top() >= d) Q->pop();
  R[x] = (ll)Q->size();
  return Q;
}

void component(int x, vi& A, vll& N, vll& R, vi& vist, vvi& G) {
  while (vist[x] != 2) {
    vist[x] = 2;
    x = A[x];
  }
  vi C;
  int ant = x;
  while (vist[x] != 3) {
    C.push_back(x);
    vist[x] = 3;
    ant = x;
    x = A[x];
  }
  int szc = (int)C.size();
  T = vll(4*szc, 0);
  auto Q = dfs(ant, 1, G, A, N, R, vist);
  while (!Q->empty()) {
    ll val = Q->top(); Q->pop();
    val = -val;
    if (val > szc) {
      act(1,0,szc-1,0,szc-1,val/szc);
      val %= szc;
    }
    if (val > 0) act(1,0,szc-1,0,(int)val-1,1);
  }
  delete Q;
  for (int i = 0; i < szc; ++i) {
    R[C[i]] += que(1,0,szc-1,i);
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vll N(n);
    for (int i = 0; i < n; ++i) cin >> N[i];
    vi A(n);
    vvi G(n);
    for (int i = 0; i < n; ++i) {
      cin >> A[i];
      G[A[i]].push_back(i);
      G[i].push_back(A[i]);
    }
    vi vist(n,0);
    vll R(n,0);
    for (int i = 0; i < n; ++i) {
      if (!vist[i]) {
        component(i, A, N, R, vist, G);
      }
    }
    for (int i = 0; i < n; ++i) {
      if (i) cout << ' ';
      cout << R[i];
    }
    cout << endl;
  }
}
