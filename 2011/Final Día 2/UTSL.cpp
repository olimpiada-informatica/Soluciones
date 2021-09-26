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
    vi V(11, 0);
    V[0] = V[10] = 1;

    int k;
    cin >> k;

    for (int i = 0; i < k; ++i){
        int x;
        cin >> x;
        V[x] = 1;
    }

    int maximum = 0;
    vi ans;

    for (int i = 1; i <= 9; ++i){
        int x = i, y = i;

        while (V[x] != 1) --x;
        while (V[y] != 1) ++y;

        int dist = min(abs(i-x), abs(i-y));
        if (dist > maximum){
            ans = {i};
            maximum = dist;
        }
        else if (dist == maximum) ans.push_back(i);
    }

    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << '\n';
}