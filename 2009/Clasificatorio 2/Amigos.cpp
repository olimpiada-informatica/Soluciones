#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

vvi G;
vector <bool> visited;

int number(int v){
    if (visited[v]) return 0;
    visited[v] = true;

    int ans = 1;
    for (int i = 0; i < G[v].size(); ++i) ans += number(G[v][i]);
    return ans; 
}

int main () {
    int n;
    int caso = 1;
    while (cin >> n){
        map <string, int> M;
        G = vvi(n);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            M[s] = cnt++;
        }

        int m;
        cin >> m;
        
        for (int i = 0; i < m; ++i){
            string a, b;
            cin >> a >> b;
            int x = M[a], y = M[b];

            G[x].push_back(y);
            G[y].push_back(x);
        }

        visited = vector <bool>(n, false);

        int minim, maxim;
        minim = maxim = number(0);

        for (int i = 1; i < n; ++i){
            if (not visited[i]){
                int num = number(i);
                minim = min(minim, num);
                maxim = max(maxim, num);
            }
        }

        cout << "Caso #" << caso++ << '\n';
        cout << "minimo grupo de amigos: " << minim << '\n';
        cout << "maximo grupo de amigos: " << maxim << '\n';
    }
}