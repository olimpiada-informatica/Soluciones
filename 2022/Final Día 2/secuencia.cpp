#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {    
    ll n;
    cin >> n;
    ll x = n*n;
    for(ll i=n-1; i >= 1; --i) {
        ll d = x%i;
        if(d == 0) d = i;
        x -= d;
    }
    cout << x << endl;
}
