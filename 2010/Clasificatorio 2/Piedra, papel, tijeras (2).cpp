#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef long long int ll;

vi V;
vector <bool> visited;

int visit(int v){
    if (visited[v]) return 0;
    visited[v] = true;

    return 1 + visit(V[v]);
}

int main (){
    int n;
    int caso = 1;

    while (cin >> n){
        map <string, int> M;
        int cnt = 0;
        V = vi(n+1, -1);
        visited = vector <bool> (n+1, false);
        vector <bool> recivied(n+1, false);

        bool possible = true;
        for (int i = 0; i < n; ++i){
            string a, b;
            cin >> a >> b;

            if (M.find(a) == M.end()) M[a] = ++cnt;
            if (M.find(b) == M.end()) M[b] = ++cnt;

            if (cnt > n) possible = false;
            else if (recivied[M[b]]) possible = false;
            else if (V[M[a]] != -1) possible = false;
            else {
                recivied[M[b]] = true;
                V[M[a]] = M[b];
            }
        }

        if (not possible) cout << "Caso " << caso++ << ": no" << endl;
        else if (visit(1) < n) cout << "Caso " << caso++ << ": no" << endl;
        else cout << "Caso " << caso++ << ": si" << endl;
    }
}