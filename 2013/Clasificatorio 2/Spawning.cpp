#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;

void update(vi& V, int k, int r, int v){
    vi W(v, 0);

    for (int i = 0; i < v-1; ++i) W[i+1] = V[i];
    for (int i = r; i < v; ++i) W[0] += k*V[i];

    V = W;
}

int sum(vi& V){
    int ans = 0;
    for (int i = 0; i < V.size(); ++i) ans += V[i];
    return ans;
}

int main (){
    int c, k, r, v, n;
    while (cin >> c >> k >> r >> v >> n){
        --r;

        vector <int> V(v, 0);
        V[0] = c;

        for (int i = 0; i < n; ++i){
            if (i > 0) cout << ",";
            cout << sum(V);
            if (i < n-1) update(V, k, r, v);
        }

        cout << endl;
    }
}