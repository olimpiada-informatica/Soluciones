#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vi a(n);
        vi b(n);
        vi dif(n-1);
        for(int i=0; i < n; ++i) {
            cin >> a[i];
            cin >> b[i];
        }
        for(int i=0; i < n-1; ++i) {
            dif[i] = a[i+1]-b[i];
        }
        sort(dif.begin(), dif.end());
        ll ans = b[n-1]-a[0];
        cout << ans << " ";
        for(int i=0; i < n-1; ++i) {
            ans -= dif[n-2-i];
            cout << ans << " ";
        }
        cout << endl;
    }
}
