#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <queue>
 
using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef pair <ll, ll> ii;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;


int main() {
    int n, m;
    int caso = 1;
    while (cin >> n >> m){
        map <int, int> H;
        map <int, int> V;

        int v;
        cin >> v;

        int last = 0;
        for (int i = 0; i < v; ++i){
            int x;
            cin >> x;

            ++V[x-last];
            last = x;
        }
        ++V[n-last];

        int h;
        cin >> h;

        last = 0;
        for (int i = 0; i < h; ++i){
            int x;
            cin >> x;

            ++H[x-last];
            last = x;
        }
        ++H[m-last];

        cout << "Case " << caso++ << '\n';
        for (auto x: H){
            int times = x.second * V[x.first];
            if (times > 0) cout << "Square " << x.first << 'x' << x.first << ": " << times << '\n';
        }
        cout << "---\n";
    }
}