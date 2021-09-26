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
    int T;
    cin >> T;

    for (int w = 0; w < T; ++w){
        int y, k, n;
        cin >> y >> k >> n;

        vi V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];

        for (int i = 0; i < k; ++i){
            y = (75 * y) % 65537;

            if (i > 0) cout << ',';
            cout << V[y%n];
        }
        cout << '.' << '\n';
    }
}