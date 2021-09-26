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


int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i){
        ll x, y;
        cin >> x >> y;
        --x;
        cout << x/y << '\n';
    }
}