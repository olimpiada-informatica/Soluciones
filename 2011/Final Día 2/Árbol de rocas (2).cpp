#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <string>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

const ll mod = 10007;


int main (){
    vvi dp(2001, vi(2001, 0));

    for (int i = 0; i <= 2000; ++i) dp[i][0] = dp[1][i] = 1;

    for (int p = 2; p <= 2000; ++p){
        for (int i = 1; i <= 2000; ++i) dp[p][i] = (dp[p-1][i] + dp[p][i-1]) % mod;
    }

    
    int k;
    while (cin >> k){
        vi V(k);
        for (int i = 0; i < k; ++i) cin >> V[i];
        
        ll total = 1;
        for (int i = 0; i < k-1; ++i) {
            total *= dp[V[i]][V[i+1]];
            total %= mod;
        }

        cout << total << '\n';
    }

}