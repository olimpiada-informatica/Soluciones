#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <string>
#include <sstream>
 
using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;

vi ans;

void permute(vi& a, int k){
    if (k == 1) return;

    if (k % 2 == 0){
        permute(a, k/2);
        fill(ans.begin(), ans.end(), 0);
        for (int i = 1; i < ans.size(); ++i){
            ans[i] = a[a[i]];
        }

        a = ans;
    }
    else{
        vi aux = a;
        permute(a, k-1);
        for (int i = 1; i < ans.size(); ++i) aux[i] = a[aux[i]];
        a = aux;
    }
}


int main (){
    int n, c, m;
    while (cin >> n >> c >> m){
        vi perm(n+1, 0);
        ans = vi(n+1, 0);

        vi cycle;
        for (int i = 0; i < c; ++i){
            cycle.clear();
            char c;
            cin >> c;

            string s;
            getline(cin, s);
            s.pop_back();

            stringstream ss(s);
            int x;
            while (ss >> x) cycle.push_back(x);


            cycle.push_back(cycle[0]);
            for (int i = 0; i < cycle.size() - 1; ++i) perm[cycle[i]] = cycle[i+1];
        }

        for (int i = 0; i < m; ++i){
            int k;
            cin >> k;

            vi aux = perm;
            permute(aux, k);

            for (int i = 1; i <= n; ++i) {
                if (i > 1) cout << ' ';
                cout << aux[i];
            }
            cout << '\n';
        }
        cout << '\n';        
    }
}   