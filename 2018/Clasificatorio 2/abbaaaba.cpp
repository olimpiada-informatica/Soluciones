#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<long long> > VVI;
const long long st = 1 << 7;
const long long mod = 1e9+7;

vector<vector<long long> > times(const VVI &a, const VVI &b){
    VVI c(a.size(), vector<long long>(a.size(), 0));
    for (long long i = 0; i < a.size(); ++i){
        for (long long j = 0; j < a.size(); ++j){
            for (long long k = 0; k < a.size(); ++k){
                c[i][j] += a[i][k]*b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

vector<vector<long long> > power(const vector<vector<long long> > &a, long long b){
    if (b == 1) return a;
    auto temp = times(a, a);
    vector<vector<long long> > res = power(temp, b/2);
    if (b % 2) res = times(res, a);
    return res;
}

int main(){
    long long n;
    cin >> n;
    if (n <= 7) cout << (1 << n) << endl;
    else{
        vector<vector<long long> > mat(st, vector<long long> (st, 0));
        for (long long i = 0; i < st; ++i){
            long long ne = (i & ((1 << 6)-1))<<1;
            if (i != 0x31) mat[i][ne] = 1;
            mat[i][ne+1] = 1;
        }
        VVI r = power(mat, n-7);
        long long res = 0;
        for (long long i = 0; i < r.size(); ++i){
            for (long long j = 0; j < r.size(); ++j){
                res += r[i][j];
                res %= mod;
            }
        }
        cout << res << endl;
    }
    
}
