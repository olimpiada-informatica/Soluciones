#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

vvi dp;
vvi V;
vi post;

bool comp (vi a, vi b){
    return a > b;
}

int rec(int T, int pos){
    if (T < 0) return 1e9;
    if (pos == V.size()) return T;

    int& ans = dp[T][pos];
    if (ans != -1) return ans;

    return ans = min(rec(T, pos+1), rec(T - V[pos][1], post[pos]));
}

int main () {
    int T, n;
    while (cin >> T >> n){

        dp = vvi(T+1, vi(n, -1));
        V = vvi(n, vi(2));

        for (int i = 0; i < n; ++i) cin >> V[i][0] >> V[i][1];

        sort(V.begin(), V.end(), comp);
        post = vi(n, n);

        for (int i = n-2; i >= 0; --i){
            if (V[i][0] == V[i+1][0]) post[i] = post[i+1];
            else post[i] = i+1;
        }

        cout << T - rec(T, 0) << '\n';
    }
}