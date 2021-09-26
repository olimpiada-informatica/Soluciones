#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;

vvi V;

int intersect(int D){
    vi object = V[0];

    for (int i = 1; i < V.size(); ++i){
        for (int j = 0; j < D; ++j) object[j] = max(object[j], V[i][j]); 
        for (int j = D; j < 2*D; ++j) object[j] = min(object[j], V[i][j]);
    }
    
    for (int i = 0; i < D; ++i){
        if (object[i+D] <= object[i]) return 0;
    }

    int ans = 1;
    for (int i = 0; i < D; ++i){
        ans *= (object[i+D] - object[i]);
    }

    return ans;
}

int main (){
    int D, n;
    cin >> D >> n;

    for (int w = 0; w < n; ++w){
        int k;
        cin >> k;

        V = vvi(k, vi(2*D));
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < 2*D; ++j) cin >> V[i][j];
        }

        cout << intersect(D) << '\n';
    }
}