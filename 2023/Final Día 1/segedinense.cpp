#include<bits/stdc++.h>

using namespace std;

using ll = long long;

bool solve(ll a, ll b) {
    if (a == b) return a % 2 == 0;
    if (a > b) swap(a, b);
    if (a % (b - a)) return false;
    if (b % 2 == 0 && a > b/2 && b % (a - b/2) == 0) return true;
    if (b % 3 == 0 && a > b/3 && b % (a - b/3) == 0) return true;
    if (b % 4 == 0 && a > b/4 && b % (a - b/4) == 0) return true;
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
       ll a, b;
       cin >> a >> b;
       cout << (solve(a, b) ? "SI" : "NO") << endl;
    }
}