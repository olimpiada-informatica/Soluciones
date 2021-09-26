#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;


vector <string> M;
vector <vector <bool> > T;
int n, m;

vvvi dp, dp2;
vvvvi come;

bool found (string& s){

    dp = vvvi(n+2, vvi(m+2, vi(s.size(), 0)));

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){

            if (s[0] == M[i-1][j-1]) dp[i][j][0] = 1;
        }
    }


    for (int k = 0; k < s.size(); ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                if (not dp[i][j][k]) continue;
                if (s[k] != M[i-1][j-1]) continue;
                if (k == s.size() - 1) return true;

                dp[i+1][j][k+1] = dp[i][j+1][k+1] = dp[i-1][j][k+1] = dp[i][j-1][k+1] = 1; 
            }
        }
    }

    return false;
}

bool mark (string& s){
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (s[0] == M[i-1][j-1]) dp[i][j][0] = 1;
        }
    }

    bool someone = false;

    for (int k = 0; k < s.size(); ++k){
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                if (not dp[i][j][k]) continue;
                if (s[k] != M[i-1][j-1]) continue;
                if (k == s.size() - 1) {
                    someone = true;
                    dp2[i][j][k] = 1;
                }
                else{
                    dp[i+1][j][k+1] = dp[i][j+1][k+1] = dp[i-1][j][k+1] = dp[i][j-1][k+1] = 1;
                    come[i+1][j][k+1][0] = come[i][j+1][k+1][1] = come[i-1][j][k+1][2] = come[i][j-1][k+1][3] = 1;
                }
            }
        }
    }

    if (someone){
        for (int k = s.size() - 1; k >= 0; --k){
            for (int i = 1; i <= n; ++i){
                for (int j = 1; j <= m; ++j){
                    if (not dp2[i][j][k]) continue;

                    T[i-1][j-1] = true;
                    if (come[i][j][k][0]) dp2[i-1][j][k-1] = 1;
                    if (come[i][j][k][1]) dp2[i][j-1][k-1] = 1;
                    if (come[i][j][k][2]) dp2[i+1][j][k-1] = 1;
                    if (come[i][j][k][3]) dp2[i][j+1][k-1] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            for (int k = 0; k < s.size(); ++k){
                dp[i][j][k] = dp2[i][j][k] = come[i][j][k][0] = come[i][j][k][1] = come[i][j][k][2] = come[i][j][k][3] = 0;
            }
        }
    }

    return someone;
}


int main () {
    string op;
    cin >> op;

    cin >> n >> m;

    M = vector <string>(n);
    T = vector <vector <bool> > (n, vector <bool> (m, false));

    dp = vvvi(n+2, vvi(m+2, vi(50, 0)));
    come = vvvvi(n+2, vvvi(m+2, vvi(50, vi(4, 0)))); 
    dp2 = vvvi(n+2, vvi(m+2, vi(50, 0)));


    for (int i = 0; i < n; ++i) cin >> M[i];

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i){
        string s;
        cin >> s;

        if (op == "BUSCA") {
            if (found(s)) cout << s << ": SI" << '\n';
            else cout << s << ": NO" << '\n';
        }
        else {
            if (mark(s)) cout << s << ": SI" << '\n';
            else cout << s << ": NO" << '\n';
        }
    }   

    if (op == "MARCA"){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (T[i][j]) cout << char(M[i][j] + 'A' - 'a');
                else cout << M[i][j];
            }
            cout << '\n';
        }
    }
}