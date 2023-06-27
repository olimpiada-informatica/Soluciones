#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        int c, k;
        cin >> n >> m >> c >> k;
        vector<vector<int>> est(n, vector<int>(m, -1e9));
        bool azul = true;
        for (int i=0; i < c; ++i) {
            int ax, ay, bx, by;
            cin >> ax >> ay >> bx >> by;
            est[ax][ay] = i;
            if (est[bx][by]+k >= i) azul = false;
        }
        cout << (azul ? "AZUL" : "AMARILLO") << endl;
    }
}