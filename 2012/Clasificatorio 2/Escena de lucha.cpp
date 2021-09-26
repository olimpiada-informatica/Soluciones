#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;


int main (){
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    cout << max(0, n + m -1) + x*n + y*m << endl;
}