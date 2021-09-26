#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef long long int ll;

vector <string> M;

const int undef = 'Z' + 1;

void solve(){
    vector <vi> dist(M.size(), vi(M[0].size(), 1e8));
    vector <vi> times(M.size(), vi(M[0].size(), 0));


    queue <vi> Q;

    for (int i = 0; i < M.size(); ++i){
        for (int j = 0; j < M[0].size(); ++j){
            if (M[i][j] == '#') dist[i][j] = -1;
            if (M[i][j] < 'A' or M[i][j] > 'Z') continue;

            Q.push({0, i, j});
            times[i][j] = M[i][j];
            dist[i][j] = 0;
        }
    }

    while (not Q.empty()){
        vi aux = Q.front(); Q.pop();

        int d = aux[0], i = aux[1], j = aux[2];
        int t = times[i][j];
        char c = t;

        if (dist[i][j] == d){
            
            if (times[i][j] < undef) M[i][j] = c;
            else M[i][j] = '*';

            if (i > 0 and dist[i-1][j] == (d+1) and times[i-1][j] != undef){
                if (times[i-1][j] != c) times[i-1][j] = undef;
            } 

            if (j > 0 and dist[i][j-1] == (d+1) and times[i][j-1] != undef) {
                if (times[i][j-1] != c) times[i][j-1] = undef;
            }
            if (i < M.size() - 1 and dist[i+1][j] == (d+1) and times[i+1][j] != undef) {
                if (times[i+1][j] != c) times[i+1][j] = undef;
            }
            if (j < M[0].size() - 1 and dist[i][j+1] == (d+1) and times[i][j+1] != undef) {
                if (times[i][j+1] != c) times[i][j+1] = undef;
            }

            if (i > 0 and dist[i-1][j] > (d+1)) {
                times[i-1][j] = t;
                Q.push({d+1, i-1, j});
                dist[i-1][j] = d + 1;
            }
            if (j > 0 and dist[i][j-1] > (d+1)) {
                times[i][j-1] = t;
                Q.push({d+1, i, j-1});
                dist[i][j-1] = d + 1;
            }
            if (i < M.size() - 1 and dist[i+1][j] > (d+1)) {
                times[i+1][j] = t;
                Q.push({d+1, i+1, j});
                dist[i+1][j] = d + 1;
            }
            if (j < M[0].size() - 1 and dist[i][j+1] > (d+1)) {
                times[i][j+1] = t;
                Q.push({d+1, i, j+1
                });
                dist[i][j+1] = d + 1;
            }
        }
    }

    for (int i = 0; i < M.size(); ++i) cout << M[i] << '\n';
}


int main (){
    int f, c;
    while (cin >> f >> c){
        string s;
        getline(cin, s);
        getline(cin, s);

        M.clear();
        while (s != "---") {
            M.push_back(s);
            getline(cin, s);
        }

        solve();
        cout << s << endl;
    }
}