#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;

int main (){
    int minimum = 1e9, maximum = -1;
    int minimumd = 0, maximumd = 0;
    int timesmin = 0, timesmax = 0;

    for (int i = 0; i < 5; ++i){
        int x, y;
        cin >> x >> y;

        if (x == minimum) ++timesmin;
        if (x == maximum) ++timesmax;

        if (x < minimum){
            minimum = x;
            timesmin = 0;   
            minimumd = y;
        }

        if (x > maximum){
            maximum = x;
            timesmax = 0;   
            maximumd = y;
        }
    }

    cout << "PIVOT ";
    if (timesmax > 0) cout << "?" << endl;
    else cout << maximumd << endl;


    cout << "BASE ";
    if (timesmin > 0) cout << "?" << endl;
    else cout << minimumd << endl;
}