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
vvvi dp;
int n, m;

const ll INF = 1e8;

vi xmove = {-2, -2, -1, -1, 1, 1, 2, 2};
vi ymove = {1, -1, 2, -2, 2, -2, 1, -1};

void rec(int k){
    if (k == 0) return; 

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            ll& value = dp[i][j][k];

            if (value == 0) continue;
            if (value > INF) value = INF + 1;

            for (int h = 0; h < 8; ++h){
                int ii = i + xmove[h];
                int jj = j + ymove[h];

                if (ii >= 0 and jj >= 0 and ii < n and jj < m) dp[ii][jj][k-1] += value;
            }
        }
    }

    rec(k-1);
}


int main() {
    int C;
    cin >> C;

    for (int h = 0; h < C; ++h){
        int k, t;
        cin >> n >> m >> k >> t;

        dp = vvvi(n, vvi(m, vi(t+1, 0)));

        for (int i = 0; i < k; ++i){
            int x, y;
            cin >> x >> y;
            --x; --y;

            ++dp[x][y][t];
        }

        rec(t);

        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (j > 0) cout << ',';
                if (dp[i][j][0] > INF) cout << ">1e8";
                else cout << dp[i][j][0];
            }
            cout << '\n';
        }
        cout << "---\n";
    }
}