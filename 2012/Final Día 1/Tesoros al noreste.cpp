#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long int ll;

vector <ll> ST;
vector <int> L, R;

void range (int p, int l, int r){
    L[p] = l;
    R[p] = r;
    if (p >= ST.size()/2) return;

    range(2*p, l, (l+r)/2);
    range(2*p+1, (l+r)/2+1, r);
    return;
}

void refresh (int p){
    if (p == 0) return;

    ST[p] = max(ST[2*p], ST[2*p+1]);
    refresh(p/2);
    return;
}

ll find_max (int l, int r, int p){
    if (L[p] > r or R[p] < l) return 0;
    if (L[p] == R[p]) return ST[p];
    if (L[p] >= l and R[p] <= r) return ST[p];

    return max(find_max(l, r, 2*p), find_max(l, r, 2*p+1));
}

int main (){
    ll n, d, x, y, z;
    cin >> n >> d;
    vector <vector <ll> > S(n, vector <ll> (3));
    for (int i = 0; i < n; ++i){
        cin >> x >> y >> z;
        S[i][0] = x;
        S[i][1] = y;
        S[i][2] = z;
    }

    sort(S.begin(), S.end());
    vector <ll> Y (n), W (n);
    map <ll, ll> M;

    for (int i=0; i<n; i++){
        Y[i] = S[i][1];
        W[i] = S[i][2];
        M[Y[i]] = Y[i];
    }
    int i = -1, last = -1;
    for (auto x : M){
        if (x.first != last){
            ++i;
            last = x.first;
        }
        M[x.first] = i;
    }

    for (int i = 0; i < n; ++i) Y[i] = M[Y[i]];
    int m = pow(2, ceil(log2(n)));

    ST = vector <ll> (2*m, 0);
    R = vector <int> (2*m);
    L = vector <int> (2*m);

    range(1, m, 2*m-1);

    for (int i = 0; i < n; ++i) {
        int pos = m + Y[i];
        ll maxim = find_max(m, pos, 1);
        ST [pos] = maxim + W[i];
        refresh(pos/2);
    }

    cout << ST[1] << endl;
}