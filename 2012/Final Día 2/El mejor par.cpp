#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvvvi> vvvvvi;

int main (){
    int n;
    cin >> n;

    int last, actual;
    cin >> last;

    int maximum = 0;
    for (int i = 1; i < n; ++i){
        cin >> actual;

        int sum = actual + last;
        if (i == 1) maximum = sum;
        else maximum = max(maximum, sum);

        last = actual;
    }

    cout << maximum << endl;
}