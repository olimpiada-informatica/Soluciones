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
    int x, y, xx, yy;
    while (cin >> x >> y >> xx >> yy){
        if (xx == x and yy == y) cout << 0 << '\n';
        else if (x == xx and x % 2 == 0) cout << 2 + abs(y - yy) << '\n';
        else if (y == yy and y % 2 == 0) cout << 2 + abs(x - xx) << '\n';
        else cout << abs(x - xx) + abs(y - yy) << '\n';
    }
}