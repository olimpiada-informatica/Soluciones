#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

vvi G;
vvi nodes;

int complete(int v, int parent){
    int ans = 1;

    for (int i = 0; i < G[v].size(); ++i){
        int u = G[v][i];

        if (u == parent) continue;

        nodes[v][i] = complete(u, v);
        ans += nodes[v][i];
    }

    return ans;
}

void fill_rest(int v, int parent, int n, int amount){
    for (int i = 0; i < G[v].size(); ++i){
        int u = G[v][i];

        if (u == parent) nodes[v][i] = n - amount;
        else fill_rest(u, v, n, nodes[v][i]);
    }
}

int main (){
    int n;
    while (cin >> n){
        G = vvi(n);
        nodes = vvi(n);

        for (int i = 0; i < n-1; ++i){
            int x, y;
            cin >> x >> y;

            G[x].push_back(y);
            G[y].push_back(x);
            nodes[x].push_back(0);
            nodes[y].push_back(1);
        }

        complete(0, -1);
        fill_rest(0, -1, n, 0);

        int minimum = n+1;

        for (int v = 0; v < n; ++v){
            int maximum = 0;

            for (int i = 0; i < G[v].size(); ++i) maximum = max(maximum, nodes[v][i]);

            minimum = min(minimum, maximum);
        }

        cout << minimum << '\n';
    }
}