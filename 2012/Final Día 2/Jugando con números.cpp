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

vi V;

set <int> complete(int l, int r){
    if (l == r) return {V[l]};

    set <int> ans;
    for (int i = l; i < r; ++i){
        set <int> A = complete(l, i);
        set <int> B = complete(i+1, r);

        for (auto x : A){
            for (auto y: B){
                ans.insert(x+y);
                ans.insert(x*y);
            }
        }
    }

    return ans;
}

int main (){
    int n;
    while (cin >> n){
        V = vi(n);
        for (int i = 0; i < n; ++i) cin >> V[i];

        set <int> S = complete(0, n-1);

        int count = 0;
        for (int x: S){
            if (count > 0) cout << ',';
            if ((++count)% 10 == 1 and count > 5) cout << '\n';
            cout << x;
        }
        cout << '.' << '\n';
    }
}