#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;

const int M = 4e4 + 1;

vector <bool> p(M, true);
vi primes;

void sieve(){
    for (ll i = 2; i < M; ++i){
        if (not p[i]) continue;

        primes.push_back(i);
        for (ll j = i*i; j < M; j += i) p[j] = false;
    }
}

void print(int n, string& format, vi& factors, vi& times){
    if (format == "NORMAL"){
        for (int i = 0; i < factors.size(); ++i){
            for (int j = 0; j < times[i]; ++j){
                if (i > 0 or j > 0) cout << ',';
                cout << factors[i];
            }
        }
        cout << '.' << '\n';
    }
    else{
        string s = to_string(n);
        for (int i = 0; i < s.size(); ++i) cout << ' ';
        for (int i = 0; i < 3; ++i) cout << ' ';


        for (int i = factors.size() - 1; i >= 0; --i){
            s = to_string(factors[i]);
            for (int j = 0; j < s.size(); ++j) cout << ' ';
            if (times[i] > 1) cout << times[i];
            if (i > 0) cout << "   ";
        }
        cout << '|' << '\n';

        cout << n <<  " = ";
        for (int i = factors.size() - 1; i >= 0; --i){
            cout << factors[i];
            if (times[i] > 1) cout << ' ';
            if (times[i] > 9) cout << ' ';
            if (i > 0) cout << " x ";
        }

        cout << '|' << '\n';
    }
}

void factorize (ll n, string& format){
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

    print(N, format, factors, times);
}


int main (){
    sieve();

    int t;
    cin >> t;

    string format;
    cin >> format;

    for (int i = 0; i < t; ++i){
        ll n;
        cin >> n;
        factorize(n, format);
    }
}