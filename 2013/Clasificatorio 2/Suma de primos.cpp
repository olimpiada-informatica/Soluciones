#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;

const int M = 5000;
const int MX = 1e6 + 1;

vi dp(M+1, -1);
vector <bool> p(M, true);
vi primes;

void sieve(){
    for (ll i = 2; i < M; ++i){
        if (not p[i]) continue;

        primes.push_back(i);
        for (ll j = i*i; j < M; j += i) p[j] = false;
    }
}

int rec(int n){
    if (n == 0) return 1;
    if (n < 0) return 0;

    int& ans = dp[n];

    if (ans != -1) return ans;

    ans = 0;
    for (int i = 0; i < primes.size(); ++i) ans += rec(n - primes[i]);

    if (ans >= MX) ans = MX;
    return ans;
}


int main (){
    sieve();

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i){
        int n;
        cin >> n;
        int ans = rec(n);

        if (ans >= MX) cout << "muchos" << endl;
        else cout << ans << endl;
    }
}