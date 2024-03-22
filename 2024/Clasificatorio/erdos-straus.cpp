#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
 
int main() {
    int T;
    cin >> T;
    while(T--) {
        ll n;
        cin >> n;
        ll N = n*(n+4);
        ll x;
        x = 0;
 
        if (n%2 == 0) {
            x = n/2;
        }
        else if (n%4 == 3) {
            x = (n+1)/4;
        }
        else {
            for (int d=3; d*d <= n+4; d += 4) {
                if (n % d == 0 || (n+4) % d == 0) {
                    x = (n+d)/4;
                }
            }
        }
 
        cout << x;
        if (x > 0) cout << " " << (n+N/(4*x-n))/4;
        cout << endl;
    }
}
