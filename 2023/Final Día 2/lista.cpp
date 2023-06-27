#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

const int MAX_V = 1000;
const ll MAX_K = 1e15;

vvi dp(MAX_V+1, vi(MAX_V+1, -1));

int ab(int x) {
    return x > 0 ? x : -x;
}

ll f(int v, int s) {
    if (v > MAX_V) return MAX_K+1;
    if (v < 0) return 0;
    if (dp[v][s] != -1) return dp[v][s];
    if (v == 0) return dp[v][s] = 1;
    if (v == 1) return dp[v][s] = 1;
    dp[v][s] = 0;
    for (int ns=max(s-v+2, 1); ns <= s+v-2; ++ns) {
        dp[v][s] += f(v-1-ab(s-ns), ns);
        if (dp[v][s] > MAX_K) return dp[v][s];
    }
    return dp[v][s];

}

int main() {
    int T;
    cin >> T;
    /*for (int i=1; i <= 5; ++i) {
            for (int j=1; j <= 5; ++j) {
                cerr << "f(" << i << ", " << j << ") = " << f(i, j) << endl;
            }
        }*/
    while (T--) {
        int v;
        ll k;
        cin >> v >> k;

        

        int s = v+2;
        for (int st=1; st <= v+1; ++st) {
                if (k <= f(v, st)) {
                    s = st;
                    break;
                }
                else {
                    k -= f(v, st);
                }
        }
        ll diff = 0;
        if (s == v+2) {
                diff = (k-1)/f(v, s);
                k = (k-1)%(f(v, s))+1;
        }
        cout << s+diff;
        while(v > 1) {
            for (int nxt=max(s-v+2, 1); nxt <= s+v-2; ++nxt) {
                //cerr << " N" << nxt;
                //cerr << " f" << f(v-(ab(s-nxt)+1), nxt);
                if (k <= f(v-(ab(s-nxt)+1), nxt)) {
                    cout << " " << nxt+diff;
                    v -= ab(s-nxt)+1;
                    s = nxt;
                    break;
                }
                else {
                    //cerr << " R" << nxt;
                    k -= f(v-(ab(s-nxt)+1), nxt);
                }
            }
        }
        //if (v == 1) cout << " " << s;
        cout << endl;
    }
}