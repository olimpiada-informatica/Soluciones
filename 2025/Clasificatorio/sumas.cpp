#include <bits/stdc++.h>
using namespace std;
#define int long long
    
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    vector<vector<int>> divisores_buenos(n+1);
    vector<vector<int>> divisores_primos(n+1);
    
    for (int i = 2; i <= n; i++) {
        bool es_divisible_potencia_primo = false;
        for (auto x : divisores_primos[i])
            if ((i/x)%x == 0) es_divisible_potencia_primo = true;
        if (!es_divisible_potencia_primo) {
            for (int j = i; j <= n; j += i) {
                divisores_buenos[j].push_back(i);
            }
        }
        
        if (divisores_primos[i].empty()) { // Es primo.
            for (int j = i; j <= n; j += i) {
                divisores_primos[j].push_back(i);
            }
        }
    }
    
    vector<int> sumas(n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i)
            sumas[i] += a[j];
    }
    
    while (q--) {
        int k; cin >> k;
        int ans = sumas[1];
        for (auto x : divisores_buenos[k]) {
            int mul = divisores_primos[x].size() % 2 == 0 ? 1 : -1;
            ans += sumas[x] * mul;
        }
        cout << ans << " ";
    }
    cout << "\n";
}
    
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    cin >> T;
    while (T--) solve();
}