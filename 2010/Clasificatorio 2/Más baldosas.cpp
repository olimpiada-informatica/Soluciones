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

int power (int n, int x){
    int ans = 1;

    for (int i = 0; i < x; ++i) ans *= n;
    return ans;
}


int main() {
    int f, c;
    while (cin >> f >> c){
        if (f == 2){
            if (c % 3 != 0) cout << 0 << '\n';
            else cout << power(2, c/3) << '\n';
        }
        else {
            if (c % 2 != 0) cout << 0 << '\n';
            else cout << power(2, c/2) << '\n';
        }
    }
}