#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <queue>
 
using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef pair <ll, ll> ii;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

vvi G;
vvi dp;
int n, m, k;

ll rec(int i, int j){
    if (j == m) return 0;
    if (G[i][j] > k) return 0;

    ll& ans = dp[i][j];
    if (ans != -1) return ans;

    ans = G[i][j];
    ll next_column = rec(i, j+1);

    for (int ii = i+1; ii < n; ++ii){
        if (G[ii][j] > k) ii = n+1;
        else {
            ans += G[ii][j];
            next_column = max(next_column, rec(ii, j+1));
        }
    }

    for (int ii = i-1; ii >= 0; --ii){
        if (G[ii][j] > k) ii = -1;
        else {
            ans += G[ii][j];
            next_column = max(next_column, rec(ii, j+1));
        }
    }

    return ans += next_column;
}


int main() {
    while (cin >> n >> m >> k){
        G = vvi(n, vi(m));
        dp = vvi(n, vi(m, -1));

        int ii, jj;

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j) {
                cin >> G[i][j];
                if (G[i][j] == 0) {
                    ii = i;
                    jj = j;
                }
            }
        }

        cout << rec(ii, jj) << endl;
    }
}