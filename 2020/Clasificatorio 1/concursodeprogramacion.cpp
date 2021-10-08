#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vi A(n), B(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ind = 0;
    for (int i = 0; i < n; ++i)
      if (A[i] > B[ind]) ++ind;

    cout << ind << endl;
  }
}
