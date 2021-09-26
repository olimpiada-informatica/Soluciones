#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <queue>
 
using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef pair <ll, ll> ii;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;


int main() {
    int n, t;
    cin >> n >> t;

    vi V(n);
    for (int i = 0; i < n; ++i) cin >> V[i];

    int start = 0;
    for (int i = 0; i < t; ++i){
        start += V[start];
        start %= n;
        if (start < 0) start += n;
    }

    cout << start << endl;
}