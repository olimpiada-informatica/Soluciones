#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

typedef long long int ll;

vector <ll> ST;
vector <int> L, R;

int m;

void range (int p, int l, int r){
    L[p]=l;
    R[p]=r;
    if (p >= m) return;

    range(2*p, l, (l+r)/2);
    range(2*p+1, (l+r)/2+1, r);
}

int find_max (int l, int r, int p){
    if (L[p] > r or R[p] < l) return 0;
    if (L[p] == R[p]) return ST[p];
    if (L[p] >= l and R[p] <= r) return ST[p];

    return max(find_max(l, r, 2*p), find_max(l, r, 2*p+1));
}

void update (int p){
    if (p == 0) return;

    ST[p] = max(ST[2*p], ST[2*p+1]);
    update (p/2);
}

void build(){
    for (int i = m-1; i > 0; --i) ST[i] = max(ST[2*i], ST[2*i+1]);
}

int points(string& s){
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) ans += s[i] - 'A' + 1;
    return ans;
}

int main (){
    int N, Q;
    cin >> N >> Q;

    m = pow(2, ceil(log2(N+1)));

    ST = vector <ll> (2*m, 0);
    R = vector <int> (2*m);
    L = vector <int> (2*m);

    range(1, m, 2*m-1);

    vector <string> V(N);
    for (int i = 0; i < V.size(); ++i) cin >> V[i];
    for (int i = 0; i < N - 1; ++i) ST[m + i] = abs(points(V[i]) - points(V[i+1]));

    build();

    for (int i = 0; i < Q; ++i){
        char c;
        cin >> c;

        if (c == 'B'){
            int x, y;
            cin >> x >> y;
            --x; --y;

            if (x > y) swap(x, y);
            cout << find_max(m+x, m+y-1, 1) << '\n';
        }
        else {
            int x;
            string s;
            cin >> x >> s;
            --x;

            V[x] = s;
            for (int i = max(0, x-1); i < min(N-1, x+1); ++i) {
                ST[m + i] = abs(points(V[i]) - points(V[i+1]));
                update((m+i)/2);
            }
        }
    }
}