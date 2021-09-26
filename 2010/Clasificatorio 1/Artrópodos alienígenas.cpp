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
    int a, b, c, d, e, f;
    while (cin >> a >> b >> c >> d >> e >> f){
    	int y = (b*e - a*f)/(b*c - a*d);
    	int x = (e - c*y)/a;

    	cout << x << " " << y << '\n';
    }
}