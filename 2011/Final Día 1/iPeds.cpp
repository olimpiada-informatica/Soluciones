#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;


int main (){
    int n;
    cin >> n;

    map <int, vi> M;

    for (int i = 0; i < n; ++i){
        int t, x;
        char c;

        cin >> t >> x >> c;
        if (M.find(t) == M.end()) M[t] = {0, 0, 0, 0};

        if (c == 'C') M[t][0] += x;
        if (c == 'P') M[t][1] += x;
        if (c == 'B') M[t][2] += x;
        if (c == 'M') M[t][3] += x;
    }

    vi actual = {0, 0, 0, 0};

    for (auto w: M){
        vi V = w.second;

        ll minimum = 0;
        for (int i = 0; i < 4; ++i){
            actual[i] += V[i];

            if (i == 0) minimum = actual[i];
            else minimum = min(minimum, actual[i]);
        }

        if (minimum > 0) {
            cout << w.first << " " << minimum << '\n';
            for (int i = 0; i < 4; ++i) actual[i] -= minimum;
        }
    }
}