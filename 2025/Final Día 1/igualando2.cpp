#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<ll>;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vi a(n);
        for (ll& x : a) cin >> x;
        if (k+1 == n) {
            vi md(n);
            ll sum = 0;
            for (ll x : a) {
                sum += n-(x%n);
                md[x%n]++;
            }
            ll ans = ll(n)*ll(n);
            for (int i=0; i < n; ++i) {
                sum -= n*md[i];
                ans = min(ans, sum);
                sum += n;
            }
            cout << ans << endl;
        }
        else {
            ll sum = 0;
            for (ll x : a) sum += x;
            cout << (n-(sum%n))%n << endl;
        }
    }
}