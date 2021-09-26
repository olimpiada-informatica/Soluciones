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
    int n, m;
    cin >> n >> m;

    int neg = 0;
    for (int i = 0; i < 5; ++i){
        int x;
        cin >> x;

        m += (n - x);
        if (m < 0) ++neg;
    }

    cout << m << endl << neg << endl;
}   