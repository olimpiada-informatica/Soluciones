#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
#include <time.h> 

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

ll evaluate(ll a, ll b, ll c, ll d, ll x){
    return a * x * x * x + b * x * x + c * x + d;
}


ll solve(ll a, ll b, ll c, ll d, ll n){
    if (evaluate(a, b, c, d, n) == 0) return n;

    ll left = 0, right = n;

    while (left < right){
        int middle = (left + right)/2;

        if (evaluate(a, b, c, d, middle) == 0) return middle;
        else if (evaluate(a, b, c, d, middle) > 0) right = middle;
        else if (evaluate(a, b, c, d, 
            middle) < 0) left = middle + 1;
    }

    return left;
}



int main() {
    ll a, b, c, d, n;
    while (cin >> a >> b >> c >> d >> n){
        cout << solve(a, b, c, -d, n) << endl;
    }
}   