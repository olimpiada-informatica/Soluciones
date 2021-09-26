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

int main (){
    char c;
    int a, b;

    cin >> c >> a >> b;

    if (c == 'M') cout << 4 + a + 2 * b << endl;
    else cout << 9 + 2 * a + 3 * b << endl;
}