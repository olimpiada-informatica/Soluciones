#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef long long int ll;

int main (){
    int n, m;
    cin >> n >> m;

    if ((n + m) % 2 == 0) cout << (n + m)/2 << endl;
    else if ((n + m) != -1) cout << (n + m) / 2 << ".5" << endl;
    else cout << "-0.5" << endl;
}