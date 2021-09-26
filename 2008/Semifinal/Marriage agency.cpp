#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

int main (){
    ll n;
    cin >> n;
    
    vi A(n), B(n);

    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    ll minim = 0, maxim = 0;

    for (ll i = 0; i < n; ++i){
        minim += abs(A[i] - B[i]);
        maxim += abs(A[i] - B[n-i-1]);
    }

    cout << minim << " " << maxim << endl;
}