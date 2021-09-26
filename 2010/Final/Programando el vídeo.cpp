#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
#include <queue>
 
using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi; 
typedef vector <ii> vii;


int main (){
    int n;
    while (cin >> n){
        vvi V(n, vi(2));

        for (int i = 0; i < n; ++i) cin >> V[i][1] >> V[i][0];

        sort(V.begin(), V.end());

        int ans = 0, last = -1;

        for (int i = 0; i < n; ++i){
            if (last >= V[i][1]) continue;

            last = V[i][0];
            ++ans;
        }

        cout << ans << endl;
    }
}