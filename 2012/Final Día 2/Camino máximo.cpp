#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvvvi> vvvvvi;

vvi G;
vvi W;

int furtherst(int v){
    priority_queue <vi> Q;
    Q.push({-0, v, -1});

    int d = -0, u = v, parent = -1;

    while (not Q.empty()){
        vi aux = Q.top(); Q.pop();

        d = aux[0];
        u = aux[1];
        parent = aux[2];

        for (int i = 0; i < G[u].size(); ++i){
            if (G[u][i] == parent) continue;

            Q.push({d-W[u][i], G[u][i], u});
        }
    }

    return u;
}

int maxdist(int v){
    priority_queue <vi> Q;
    Q.push({-0, v, -1});

    int d = -0, u = v, parent = -1;

    while (not Q.empty()){
        vi aux = Q.top(); Q.pop();

        d = aux[0];
        u = aux[1];
        parent = aux[2];

        for (int i = 0; i < G[u].size(); ++i){
            if (G[u][i] == parent) continue;
            Q.push({d-W[u][i], G[u][i], u});
        }
    }

    return -d;
}

int main (){
    int n;
    while (cin >> n){
        G = vvi(n);
        W = vvi(n);

        for (int i = 0; i < n-1; ++i){
            int x, y, w;
            cin >> x >> y >> w;
            --x; --y;

            G[x].push_back(y);
            G[y].push_back(x);
            W[x].push_back(w);
            W[y].push_back(w);
        }   
        
        int v = furtherst(0);
        cout << maxdist(v) << '\n';
    }
}