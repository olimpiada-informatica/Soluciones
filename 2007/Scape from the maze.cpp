#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long int ll;

int main (){
    int n, m;
    while (cin >> n >> m){
        if (n == m and n == 0) break
        vector <string> V(n);
        vector <vector<ll> > dp(n, vector <ll>(m, 0));

        for (int i = 0; i < n; ++i) cin >> V[i];
        dp[n-1][m-1] = 1;

        for (int i = m-2; i >= 0; --i)
            if (V[n-1][i] != 'X') dp[n-1][i] = dp[n-1][i+1];

        for (int i = n-2; i >= 0; --i){
            if (V[i][m-1] != 'X') dp[i][m-1] = dp[i+1][m-1];

            for (int j = m-2; j >= 0; --j){
                 if (V[i][j] != 'X') {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                    if (dp[i][j] > 1e6) dp[i][j] = 1e6;
                 }
            }
        }

        if (dp[0][0] >= 1e6) cout << "!!!" << endl;
        else cout << dp[0][0] << endl;
    }
}