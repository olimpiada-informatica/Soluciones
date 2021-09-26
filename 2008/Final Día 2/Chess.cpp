#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

vector <string> T;
vector <vector <bool> > safe;
vvi P;

int x, y;

bool comp(vi a, vi b){
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}

void rook(int a, int b){
    for (int i = a+1; i < 8; ++i){
        if (T[i][b] != '.') {
            safe[i][b] = false;
            i = 10;
        }
        else safe[i][b] = false;
    }
    for (int i = a-1; i >= 0; --i){
        if (T[i][b] != '.') {
            safe[i][b] = false;
            i = -10;
        }
        else safe[i][b] = false;
    }
    for (int j = b+1; j < 8; ++j){
        if (T[a][j] != '.') {
            safe[a][j] = false;
            j = 10;
        }
        else safe[a][j] = false;
    }
    for (int j = b-1; j >= 0; --j){
        if (T[a][j] != '.') {
            safe[a][j] = false;
            j = -10;
        }
        else safe[a][j] = false;
    }
}

void bishop(int a, int b){
    for (int k = 1; a+k < 8 and b+k < 8; ++k){
        if (T[a+k][b+k] != '.') {
            safe[a+k][b+k] = false;
            k = 10;
        }
        else safe[a+k][b+k] = false;
    }
    for (int k = 1; a+k < 8 and b-k >= 0; ++k){
        if (T[a+k][b-k] != '.') {
            safe[a+k][b-k] = false;
            k = 10;
        }
        else safe[a+k][b-k] = false;
    }
    for (int k = 1; a-k >= 0 and b+k < 8; ++k){
        if (T[a-k][b+k] != '.') {
            safe[a-k][b+k] = false;
            k = 10;
        }
        else safe[a-k][b+k] = false;
    }
    for (int k = 1; a-k >= 0 and b-k >= 0; ++k){
        if (T[a-k][b-k] != '.') {
            safe[a-k][b-k] = false;
            k = 10;
        }
        else safe[a-k][b-k] = false;
    }
}

void solve(){
    for (int i = 0; i < P.size(); ++i){
        if (P[i][0] == 0) {
            rook(P[i][1], P[i][2]);
            bishop(P[i][1], P[i][2]);
        }
        if (P[i][0] == 1) bishop(P[i][1], P[i][2]);
        if (P[i][0] == 2) rook(P[i][1], P[i][2]);
    }

    vvi safe_positions;

    for (int i = -1; i <= 1; ++i){
        for (int j = -1; j <= 1; ++j){
            if (i == 0 and j == 0) continue;

            int ii = i + x;
            int jj = j + y;

            if (ii < 0 or jj < 0 or ii >= 8 or jj >= 8) continue;
            if (safe[ii][jj]) safe_positions.push_back({ii, jj});
        }
    } 

    if (safe_positions.empty()){
        if (safe[x][y]) cout << " stalemate" << endl;
        else cout << " checkmate" << endl;
    }
    else {
        sort(safe_positions.begin(), safe_positions.end()

            );

        for (vi q: safe_positions){
            cout << " " << char('a' + q[0]) << q[1] + 1;
        }
        cout << endl;
    }
}


int main(){
    int cases;
    cin >> cases;

    map <char, int> M;
    M['Q'] = 0;
    M['B'] = 1;
    M['R'] = 2;

    for (int w = 0; w < cases; ++w){

        string s;
        cin >> s;

        x = s[0] - 'a';
        y = s[1] - '1';

        int n;
        cin >> n;

        P = vvi(n);
        T = vector <string>(8, string(8, '.'));
        safe = vector <vector <bool> > (8, vector <bool>(8, true));

        for (int i = 0; i < n; ++i){
            string t; cin >> t;

            int piece = M[t[0]];
            int a = t[1] - 'a';
            int b = t[2] - '1';
            T[a][b] = '0' + piece;

            P[i] = {piece, a, b};
        }

        cout << w+1 << ":";
        solve();
    }
}