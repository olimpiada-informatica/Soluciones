#include<bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> mindiv;
vector<int> primes;

const int SIEVE_LIM = 1e6+5;

void sieve(int N) {
    mindiv = vector<int>(N+1, 0);
    primes = vector<int>();
    for(int i=2; i <= N; ++i) {
        if(mindiv[i] == 0) {
            mindiv[i] = i;
            primes.push_back(i);
        }
        for(int j=0; j < (int)primes.size() and primes[j] <= mindiv[i] and primes[j]*i <= N; ++j) {
            mindiv[i*primes[j]] = primes[j];
        }
    }
}

vector<ll> primefactors(ll x) {
    vector<ll> ans;
    if (x <= SIEVE_LIM) {
        while (x > 1) {
            ll d = mindiv[x];
            ans.push_back(d);
            while(x % d == 0) x /= d;
        }
        return ans;
    }
    for (int p : primes) {
        if (x % p == 0) {
            ans.push_back(p);
            while (x % p == 0) x /= p;
        }
    }
    if (x > 1) ans.push_back(x);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(SIEVE_LIM);

    int n;
    cin >> n;

    
    vector<ll> a;

    ll best_ans = 2;       
    ll best_count = 0;

    for (int i=0; i < n; ++i) {
        ll x;
        cin >> x;
        if (x > 1) {            
            a.push_back(x);
            best_count += x%2;
        }
    }

    n = (int)a.size();          
    if (n == 0) {
        cout << 2 << endl;
        return 0;
    }

    set<ll> tried;
    tried.insert(2);

    auto try_num = [&] (ll d) {
        if (tried.count(d)) return;
        tried.insert(d);
        ll c = 0;
        for (int i=0; i < n; ++i) {
            c += a[i]%d;
            if (c > best_count) return;
        }
        if (c < best_count || (c == best_count && d < best_ans)) {      
            best_count = c;
            best_ans = d;
        }
    };

    auto try_div = [&] (ll x) {
        vector<ll> pf = primefactors(x);
        for (ll y : pf) try_num(y);
    };

    const int NUM_IT = 20;              
                                        
    mt19937 rng;

    for (int z=0; z < NUM_IT; ++z) {
        int i = uniform_int_distribution<>(0, n-1)(rng);
        try_div(a[i]);                      
        try_div(a[i]-1);     
    }

    cout << best_ans << endl;
}
