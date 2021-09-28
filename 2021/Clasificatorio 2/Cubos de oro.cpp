#include <bits/stdc++.h>
using namespace std;

// solucion 100 pts

using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vvvvi = vector<vvvi>;

const int MIN_ORO = 100;
const int PRECIO = 5;

vvvvi dp;
int V, A, B, C, P1, P2, P3;

int f(int act, int a, int b, int c) {
    if (act == 0) return 0;
    int& ans = dp[act][a][b][c];
    if (ans == -1) {
        ans = 0;
        if (a > 0) {
            if (A < act) ans = max(ans, f(act-A, a-1, b, c) - A*PRECIO);
            else ans = max(ans, f(MIN_ORO, a-1, b, c) - A*PRECIO + V);
        }
        if (b > 0) {
            if (B < act) ans = max(ans, f(act-B, a, b-1, c) - B*PRECIO);
            else ans = max(ans, f(MIN_ORO, a, b-1, c) - B*PRECIO + V);
        }
        if (c > 0) {
            if (C < act) ans = max(ans, f(act-C, a, b, c-1) - C*PRECIO);
            else ans = max(ans, f(MIN_ORO, a, b, c-1) - C*PRECIO + V);
        }
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> V >> A >> B >> C >> P1 >> P2 >> P3;
        V *= 100; // pasamos de euros a céntimos
        dp = vvvvi(MIN_ORO+1, vvvi(P1+1, vvi(P2+1, vi(P3+1, -1))));
        int optimo = 0;
        for (int a = 0; a <= P1; ++a) {
            for (int b = 0; b <= P2; ++b) {
                for (int c = 0; c <= P3; ++c) {
                    int gramos = a*A + b*B + c*C;
                    int benef = V - gramos*PRECIO;
                    if (gramos >= MIN_ORO and benef < 0) { // garantizamos que en este cubo gana el cliente
                        optimo = max(optimo, benef + f(MIN_ORO, P1-a, P2-b, P3-c));
                    }
                }
            }
        } 
        cout << optimo << endl;
    }
}
