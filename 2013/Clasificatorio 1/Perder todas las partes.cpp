#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef long long int ll;

int main (){
    int k, n;
    while (cin >> k >> n){
        int minimum = 0;
        int maximum = k;

        for (int i = 0; i < n; ++i){
            int p;
            cin >> p;

            maximum = min(maximum, p);
            minimum += k - p;
        }

        minimum = max(0, k - minimum);

        cout << minimum << " " << maximum << endl;
    }
}