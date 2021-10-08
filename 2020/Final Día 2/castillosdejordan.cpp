#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int oo = 1e9+7;

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n;
        cin >> n;

        vector<int> a(n + 1, oo);
        ll ans = 0;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] > n) {
                ans += a[i] - n;
                a[i] = n;
            }
        }

        int j = n;
        for(int i = 1; i <= n; i++) {
            while(a[j] < i) j--;    
            assert(a[j] >= i);

            if(a[i] > j) {
                ans += a[i] - j;
                a[i] = j;
            }
            
            while(j > a[i]) {
                ans += a[j] - (i - 1);
                a[j] = i - 1;
                j--;
            }
        }

        cout << ans << '\n';
    }

}
