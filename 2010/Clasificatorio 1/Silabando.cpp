#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <string>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

vector <string> V;
vector <int> P;
vector <bool> used;
int n, k;

void show(){
    if (P.empty()) return;

    for (int i = 0; i < P.size(); ++i){
        cout << V[P[i]];
    }

    cout << '\n';
}

void rec(int pos){
    show();

    if (pos == k) return;

    for (int i = 0; i < n; ++i){
        P.push_back(i);
        rec(pos + 1);
        P.pop_back();
    }
}

int main (){
    cin >> n >> k;
    
    used = vector <bool> (n, false);
    V = vector <string> (n);

    for (int i = 0; i < n; ++i) cin >> V[i];
    sort(V.begin(), V.end());

    rec(0);
}