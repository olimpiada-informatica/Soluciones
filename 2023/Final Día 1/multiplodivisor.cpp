#include<bits/stdc++.h>

using ll = long long;
using namespace std;

#define int ll

using vi = vector<int>;

int n_debug;


bool ask_debug(int m) {
    return (n_debug%m == 0 || m%n_debug == 0);
}

int ask_dist_debug(int m) {
    if(ask_debug(m)) return 0;
    if(m > n_debug) return min(m%n_debug, n_debug-m%n_debug);
    if(m > n_debug/2+n_debug/3) {
        if (n_debug%2) {
            return n_debug-m;
        }
        return min(n_debug-m, m-n_debug/2);
    }
    for (int d=1; true; d++) {
        if (ask_debug(m+d) || (m > d && ask_debug(m-d))) return d;
    }
}

bool ask(int m) {
    cout << "? 1 " << m << endl;

    //return ask_debug(m);

    string s;
    cin >> s;
    if(s == "SI") return true;
    else if (s == "NO") return false;
    else exit(0);
    return false;
}

int ask_dist(int m) {
    cout << "? 2 " << m << endl;

    //return ask_dist_debug(m);

    int d;
    cin >> d;
    if (d == -1) exit(0);
    return d;
}

void answer(int n) {
    cout << "! " << n << endl;
    char c;
    cin >> c;
    if (c == '-') exit(0);
}

const int SIEVE_LIM = 1e7;
const int MAX_N = 1e18;

vector<bool> is_prime;
vi primes;

void sieve() {
    is_prime = vector<bool>(SIEVE_LIM+1, true);
    is_prime[1] = false;
    primes = vi();
    for (int i=2; i <= SIEVE_LIM; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j=2; j*i <= SIEVE_LIM; ++j) {
                is_prime[j*i] = false;
            }
        }
    }
}

int get_nearest(int x) {
    int d = ask_dist(x);
    if(ask(x+d)) return x+d;
    return x-d;
}

int determine_factor(int n, int p) {

    vi powp;
    powp.push_back(1);
    int nn = n;
    while (nn%p == 0) {
        nn /= p;
        powp.push_back(powp.back()*p);
    }
    int e = powp.size();
    int l = 0;
    int r = e;
    while(r-l > 1) {
        int mid = (l+r)/2-1;
        int cand_mul = (n/powp[e-mid-1])*(p+1);
        if(ask(cand_mul)) {
            r = mid+1;
        }
        else {
            l = mid+1;
        }
    }
    return n/powp[e-l-1];
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int handle_big_factors(int n, int a) {

    if (a > SIEVE_LIM) {
        return determine_factor(n, n/a);
    }
    mt19937 gen;
    int n2 = get_nearest(uniform_int_distribution<ll>(n, 2*MAX_N)(gen));
    return gcd(n, n2);
}

int solve() {
    int n = get_nearest(MAX_N);
    int a = 1;
    for (int p : primes) {
        n = determine_factor(n, p);
        while ((n/a)%p == 0) a *= p;
    }
    if (n != a) {
        n = handle_big_factors(n, a);
    }
    return n;
}

signed main() {
    sieve();
    int T;
    cin >> T;
    while (T--) {
        //cin >> n_debug;
        answer(solve());
    }
}