#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

string s;
int n;

int number = 1;

void rec(int pos, int x, int y, int z, int a, int b, int c, int d){
    if (number > 10000) return;

    if (pos > 3){
        if (a != 0 and b != 0 and c != 0 and d != 0) return;
        if (a != 1 and b != 1 and c != 1 and d != 1) return;
        if (a != 2 and b != 2 and c != 2 and d != 2) return;
    }

    int limit = (n - pos)/4;
    if (x < limit or y < limit or z < limit) return;

    if (x == 0 and y == 0 and z == 0){
        cout << s << '\n';
        ++number;
        return;
    }

    s[pos] = 'C';
    if (x > 0) rec(pos + 1, x - 1, y, z, 0, a, b, c);

    s[pos] = 'D';
    if (y > 0) rec(pos + 1, x, y - 1, z, 1, a, b, c);

    s[pos] = 'E';
    if (z > 0) rec(pos + 1, x, y, z - 1, 2, a, b, c);
}


int main () {
    int x, y;
    cin >> n >> x >> y;

    int z = n - x - y;
    int limit = n/4;
    
    s = string(n, '.');
    rec(0, x, y, n - x - y, -1, -1, -1, -1);
    if (number == 1) cout << "NO" << '\n';
}