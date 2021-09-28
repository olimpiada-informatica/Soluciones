#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <cassert>
#include <time.h>
#include <chrono>
#include <random>

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> ii;
typedef vector <ii> vii;
typedef vector <ll> vi;
typedef vector <vi> vvi;

ll n, k;
vii V;

bool possible(ll m){
    ll total = 1, last = -1;

    for (ll i = 0; i < n; ++i){
        if (last == -1) last = V[i].first;
        if (last + m >= V[i].first + V[i].second) continue;

        if (last + m <= V[i].first){
            ++total;
            last = V[i].first;
        }
        else {
            ++total;
            last += m;
        }



        ll lines = ((V[i].first + V[i].second - last - 1)/m);
        //cout << total << " and " << last << " vs " << V[i].first + V[i].second << " and m = " << m << " --> " << lines << endl;

        total += lines;
        last += lines * m;
    }

    return total <= k;
}


int main(){
    ll t;
    cin >> t;

    for (ll w = 0; w < t; ++w){
        cin >> n >> k;
        V = vii(n);
        for (ll i = 0; i < n; ++i) cin >> V[i].first >> V[i].second;
        sort(V.begin(), V.end());

        ll l = 1, r = 2e9;

        while (l + 1 < r){
            ll m = (l + r)/2;

            if (possible(m)) r = m;
            else l = m + 1;
        }

        if (not possible(l)) ++l;
        cout << l << endl;
    }
}