#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef long long int ll;

const int M = 1e6 + 1;

vector <bool> prime(M, true);

void sieve(){
    prime[0] = prime[1] = false;
    for (ll i = 2; i < M; ++i){
        if (not prime[i]) continue;

        for (ll j = i*i; j < M; j += i) prime[j] = false;
    }
}

int pseudoprime(int x){
    int ans = 0;
    int power = 1;

    while (x > 0){
        int d = x % 10;
        x /= 10;
        if (not prime[d]) continue;

        ans += d * power;
        power *= 10;
    }

    return prime[ans];
}

int main (){
    sieve();

    vi V(M, 0);
    V[2] = 1;

    for (int i = 3; i < M; ++i){
        V[i] = V[i-1] + pseudoprime(i);
    }

    int n;
    while (cin >> n) cout << V[n] << '\n';
}