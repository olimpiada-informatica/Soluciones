#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef long long int ll;

const int M = 1e5 + 1;

vector <bool> p(M, true);
vi primes;

void sieve(){
    for (ll i = 2; i < M; ++i){
        if (not p[i]) continue;

        primes.push_back(i);
        for (ll j = i*i; j < M; j += i) p[j] = false;
    }
}

void factorize (ll n){
    ll N = n;

    vector <ll> factors;
    vi times;

    for (int i = 0; i < primes.size() and primes[i]*primes[i] <= n; ++i){
        int p = primes[i];

        if (n % p == 0){
            factors.push_back(p);
            times.push_back(0);

            while (n % p == 0){
                ++times.back();
                n /= p;
            }
        }
    }

    if (n > 1) {
        factors.push_back(n);
        times.push_back(1);
    }

    cout << N << "=";
    for (int i = 0; i < factors.size(); ++i) {
        if (i > 0) cout << "*";
        cout << factors[i];
        if (times[i] > 1) cout << "^" << times[i];
    }
    
    cout << endl;
}


int main (){
    sieve();

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i){
        ll n;
        cin >> n;
        factorize(n);
    }
}