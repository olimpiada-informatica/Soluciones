#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vi V(n,0);
        for (int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            ++V[x];
            ++V[y];
        }
        ll res = n*(n-1)*(n-2)/6 - (n-1)*(n-2);
        for (int i = 0; i < n; ++i) res += V[i]*(V[i]-1)/2;
        cout << res << endl;
    }
}
