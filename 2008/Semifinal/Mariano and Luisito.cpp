#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long int ll;

const ll inf = 5e4

int main (){
    ll n, m;
    cin >> m >> n;
    
    vector <string> V(n);
    vector <vector<ll> > dp(n, vector <ll>(m, inf));

    for (int i = 0; i < n; ++i) cin >> V[i];

    for (int i = 0; i < m; ++i) {
        if (V[0][i] == 'M') dp[0][i] = 0;
    }

    for (int i = 1; i < n; ++i){
        if (V[i][0] != '*') {
            dp[i][0] = min(dp[i-1][0], 1 + dp[i-1][1]);
            if (V[i][0] == 'T') dp[i][0] += 3;
        }
        if (V[i][m-1] != '*') {
            dp[i][m-1] = min(dp[i-1][m-1], 1 + dp[i-1][m-2]);
            if (V[i][m-1] == 'T') dp[i][m-1] += 3;
        }

        for (int j = 1; j < m-1; ++j){
            if (V[i][j] != '*'){
                dp[i][j] = min(1 + dp[i-1][j-1] , min(1 + dp[i-1][j+1], dp[i-1][j]));
                if (V[i][j] == 'T') dp[i][j] += 3;
            }
        }
    }

    ll minim = inf;

    for (int i = 0; i < m; ++i) minim = min(minim, dp[n-1][i]);

    if (minim == inf) cout << "IMPOSSIBLE" << endl;
    else cout << minim << endl;
}