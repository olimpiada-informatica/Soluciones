#include <bits/stdc++.h>

using namespace std;

vector <long long> row;
long long t, n, a;

long long check (long long q) {
    long long total = 0;
    long long local = 0;
    for (long long i = 0; i < n; i++) {
        if (row[i+1]-row[i] <= q) local++;
        else {
            total += (local*(local+1))/2;
            local = 0;
        }
    }
    return total;
}

long long posicio(long long esq, long long dre) {
    long long mig = (esq+dre)/2;
    if (esq==dre) return esq;
    long long x = check(mig);
    if (x >= a) return posicio(esq, mig);
    return posicio(mig+1, dre);
}

int main () {
    while (cin >> t) {
        for (long long tt = 0; tt < t; tt++) {
            cin >> n >> a;
            row = vector <long long> (n+1);
            for (long long i = 0; i < n; i++) cin >> row[i];
            row[n] = 1e10;
            long long res = posicio(0,1e9-1);
            cout << res << endl;
        }
    }
}
