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
   int u1, u2, u3, v1, v2, v3;
   cin >> u1 >> u2 >> u3 >> v1 >> v2 >> v3;

   cout << u2 * v3 - u3 * v2 << " ";
   cout << u3 * v1 - u1 * v3 << " ";
   cout << u1 * v2 - u2 * v1 << endl;
}