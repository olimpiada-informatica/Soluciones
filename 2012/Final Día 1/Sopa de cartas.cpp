#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
#include <time.h> 

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;


vector <string> M, W;
vvi H;
vvi V;
vvi D1, D2;
map <char, char> after, before;

int best_equal(int n, int m){
    int ans = 0;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (M[i][j] != M[i-1][j]){
                int value = 1;
                for (int k = i+1; k <= n and M[k][j] == M[k-1][j]; ++k) ++value;
                V[i][j] = value;
                ans = max(ans, value);
            }

            if (M[i][j] != M[i][j-1]){
                int value = 1;
                for (int k = j+1; k <= m and M[i][k] == M[i][k-1]; ++k) ++value;
                H[i][j] = value;
                ans = max(ans, value);
            }

            if (M[i][j] != M[i-1][j-1]){
                int value = 1;
                for (int k = 1; k + j <= m and k + i <= n and M[i+k][j+k] == M[i+k-1][j+k-1]; ++k) ++value;
                D1[i][j] = value;
                ans = max(ans, value);
            }

            if (M[i][j] != M[i-1][j+1]){
                int value = 1;
                for (int k = 1; j - k > 0 and k + i <= n and M[i+k][j-k] == M[i+k-1][j-k+1]; ++k) ++value;
                D2[i][j] = value;
                ans = max(ans, value);
            }
        }
    }
    return ans;
}

int best_inc(int n, int m){
    int ans = 0;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (M[i][j] != after[M[i-1][j]]){
                int value = 1;
                for (int k = i+1; k <= n and M[k][j] == after[M[k-1][j]]; ++k) ++value;
                V[i][j] = max(V[i][j], value);
                ans = max(ans, value);
            }

            if (M[i][j] != after[M[i][j-1]]){
                int value = 1;
                for (int k = j+1; k <= m and M[i][k] == after[M[i][k-1]]; ++k) ++value;
                H[i][j] = max(H[i][j], value);
                ans = max(ans, value);
            }

            if (M[i][j] != after[M[i-1][j-1]]){
                int value = 1;
                for (int k = 1; k + j <= m and k + i <= n and M[i+k][j+k] == after[M[i+k-1][j+k-1]]; ++k) ++value;
                D1[i][j] = max(D1[i][j], value);
                ans = max(ans, value);
            }

            if (M[i][j] != after[M[i-1][j+1]]){
                int value = 1;
                for (int k = 1; j - k > 0 and k + i <= n and M[i+k][j-k] == after[M[i+k-1][j-k+1]]; ++k) ++value;
                D2[i][j] = max(D2[i][j], value);
                ans = max(ans, value);
            }
        }
    }
    return ans;
}

int best_dec(int n, int m){
    int ans = 0;

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (M[i][j] != before[M[i-1][j]]){
                int value = 1;
                for (int k = i+1; k <= n and M[k][j] == before[M[k-1][j]]; ++k) ++value;
                V[i][j] = max(V[i][j], value);
                ans = max(ans, value);
            }

            if (M[i][j] != before[M[i][j-1]]){
                int value = 1;
                for (int k = j+1; k <= m and M[i][k] == before[M[i][k-1]]; ++k) ++value;
                H[i][j] = max(H[i][j], value);
                ans = max(ans, value);
            }

            if (M[i][j] != before[M[i-1][j-1]]){
                int value = 1;
                for (int k = 1; k + j <= m and k + i <= n and M[i+k][j+k] == before[M[i+k-1][j+k-1]]; ++k) ++value;
                D1[i][j] = max(D1[i][j], value);
                ans = max(ans, value);
            }

            if (M[i][j] != before[M[i-1][j+1]]){
                int value = 1;
                for (int k = 1; j - k > 0 and k + i <= n and M[i+k][j-k] == before[M[i+k-1][j-k+1]]; ++k) ++value;
                D2[i][j] = max(D2[i][j], value);
                ans = max(ans, value);
            }
        }
    }
    return ans;
}

void update(int d, int n, int m){
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m; ++j){
            if (H[i+1][j+1] == d){
                for (int k = 0; k < d; ++k) W[i][j+k] = 'x';
            }
            if (V[i+1][j+1] == d){
                for (int k = 0; k < d; ++k) W[i+k][j] = 'x';
            }
            if (D1[i+1][j+1] == d){
                for (int k = 0; k < d; ++k) W[i+k][j+k] = 'x';
            }
            if (D2[i+1][j+1] == d){
                for (int k = 0; k < d; ++k) W[i+k][j-k] = 'x';
            }
        }
    }
}

void init(){
    after['A'] = '2';
    after['2'] = '3';
    after['3'] = '4';
    after['4'] = '5';
    after['5'] = '6';
    after['6'] = '7';
    after['7'] = '8';
    after['8'] = '9';
    after['9'] = 'T';
    after['T'] = 'J';
    after['J'] = 'Q';
    after['Q'] = 'K';
    after['K'] = 'A';

    before['A'] = 'K';
    before['2'] = 'A';
    before['3'] = '2';
    before['4'] = '3';
    before['5'] = '4';
    before['6'] = '5';
    before['7'] = '6';
    before['8'] = '7';
    before['9'] = '8';
    before['T'] = '9';
    before['J'] = 'T';
    before['Q'] = 'J';
    before['K'] = 'Q';

    after['.'] = before['.'] = '.';
}

int main() {
    init();

    int n, m;
    cin >> n >> m;

    H = vvi(n+1, vi(m+1, 0));
    V = vvi(n+1, vi(m+1, 0));
    D1 = vvi(n+1, vi(m+1, 0));
    D2 = D1;
    M = vector <string>(n+1, string(m+2, '.'));
    W = vector <string>(n, string(m, '.'));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j){
            cin >> M[i][j];
            W[i-1][j-1] = M[i][j];
        }
    }

    int d = best_equal(n, m);
    d = max(d, best_inc(n,m));
    d = max(d, best_dec(n,m));
    
    update(d, n, m);
    for (int i = 0; i < n; ++i) cout << W[i] << '\n';
}   