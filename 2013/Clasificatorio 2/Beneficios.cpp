#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef long long int ll;

int main (){
    int n;
    while (cin >> n){
        int minimum = 1;

        for (int j = 0; j < n; ++j) {
            int m;
            cin >> m;
            minimum = min(minimum, m);
        }

        if (minimum > 0) cout << "PREMIO" << endl;
        else cout << "NO" << endl;
    }
}