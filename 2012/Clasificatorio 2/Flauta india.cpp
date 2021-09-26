#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvvvi> vvvvvi;

vvvvvi dp(21, vvvvi(31, vvvi(31, vvi(21, vi(21, -1)))));

ll rec(int n, int k, int pos, int last, int prelast){
    if (pos == k) return last == n;
    if (last < 1 or last > n) return 0;

    ll& ans = dp[n][k][pos][last][prelast];
    if (ans != -1) return ans;

    ans = rec(n, k, pos + 1, last+1, last) + rec(n, k, pos + 1, last-1, last);
    if (last != prelast) ans += rec(n, k, pos + 1, last, last);

    return ans;
}

int main (){
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i){
        int n, k;
        cin >> n >> k;

        cout << rec(n, k, 1, 1, 0) << '\n';
    }
}