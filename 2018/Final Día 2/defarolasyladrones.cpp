#include <bits/stdc++.h>
using namespace std;

struct Farola {
    int l, r;
    bool operator<(const Farola& b) const {
        if(l != b.l) return l < b.l;
        else return r < b.r;
    }
};

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> vecinos(n);
        vector<Farola> farolas(m);

        for(int i = 0; i < n; i++) {
            cin >> vecinos[i];
        }
        for(int i = 0; i < m; i++) {
            int y, r;
            cin >> y >> r;
            int l = y - r, _r = y + r;
            farolas[i] = Farola({l, _r});
        }

        sort(farolas.begin(), farolas.end());
        sort(vecinos.begin(), vecinos.end());

        int j = 0;
        int r = -((int)1e9);
        int ans = 0;
        bool valid = true;

        for(int i = 0; i < n && valid; i++) {
            int posicion = vecinos[i];
            if(r >= posicion) continue;

            while(j < m && farolas[j].l <= posicion) {
                r = max(r, farolas[j].r);
                j++;
            }

            ans++;
            if(r < posicion) valid = false;
        }

        if(!valid) cout << "imposible\n";
        else cout << ans << '\n';
    }

}
