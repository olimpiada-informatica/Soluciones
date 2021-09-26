#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

int main(){
    int n, p, k;
    cin >> n >> p >> k;

    vvi V(n, vi(p, 0));

    for (int i = 0; i < k; ++i){
        int x, y, p;
        cin >> x >> y >> p;

        V[x][y] = max(V[x][y], p);
    }

    vi P(n, 0);

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < p; ++j) P[i] += V[i][j];
    }

    int maxim = -1;
    int times = 0;
    int person = 0;

    for (int i = 0; i < n; ++i){
        if (P[i] == maxim) ++times;
        if (P[i] > maxim){
            maxim = P[i];
            times = 1;
            person = i;
        }
    }

    cout << maxim << " ";
    if (times == 1) cout << person << endl;
    else cout << -1 << endl;
}