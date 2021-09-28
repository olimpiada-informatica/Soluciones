#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <complex>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <ll> vll;
typedef vector <vll> vvll;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef pair <int, int> ii;

map <ll, ll> M;

bool palindrome(ll a){
    string s = to_string(a);

    int n = s.size();
    int till = n/2;
    for (int i = 0; i < till; ++i){
        if (s[i] != s[n-1-i]) return false;
    }

    return true;
}

ll next(ll a){
    ll ap = 0, ca = a;

    while (ca){
        ap = ap * 10 + ca % 10;
        ca /= 10;
    }

    return (a + ap)/2;
}

ll find_one(ll a){
    if (M.find(a) != M.end()) return M[a];

    if (not palindrome(a)) {
        M[a] = -1;
        return M[a] = find_one(next(a));
    }
    return M[a] = a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i){
        ll x;
        cin >> x;
        ll ans = find_one(x);
        if (ans == -1) cout << "Que complicado!" << endl;
        else cout << ans << endl;
    }
}

