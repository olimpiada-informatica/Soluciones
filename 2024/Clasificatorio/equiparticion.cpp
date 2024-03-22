#include<bits/stdc++.h>

using namespace std;

using ll = long long; 

struct P {
    ll x, y, v;
};

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<P> v(n);
        ll sum = 0;
        for (int i=0; i < n; ++i) {
            cin >> v[i].x >> v[i].y >> v[i].v;
            sum += v[i].v;
        }

        if (sum%4) {
            cout << 0 << endl;
            continue; 
        }

        ll a, an, b, bn;
        a = an = b = bn = 0;

        sort(v.begin(), v.end(), [] (P a, P b) {return a.x < b.x;});
        ll cs = 0;
        for (int i=0; i < n-1; ++i) {
            cs += v[i].v;
            if (cs == sum/2) {
                a = v[i].x;
                an = v[i+1].x;
            }
        }

        sort(v.begin(), v.end(), [] (P a, P b) {return a.y < b.y;});
        cs = 0;
        for (int i=0; i < n-1; ++i) {
            cs += v[i].v;
            if (cs == sum/2) {
                b = v[i].y;
                bn = v[i+1].y;
            }
        }

        vector<vector<ll>> sums(2, vector<ll>(2, 0));

        for (int i=0; i < n; ++i) {
            sums[v[i].x<=a][v[i].y<=b] += v[i].v;
        }

        if (sums[0][0] == sums[0][1] && sums[0][1] == sums[1][0] && sums[1][0] == sums[1][1]) {
            cout << (an-a)*(bn-b) << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}
