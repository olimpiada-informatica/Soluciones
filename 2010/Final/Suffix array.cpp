#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

vvvi V;

bool first = true;
const int alfa = 'z' - 'a' + 1;
string s;
    
void rec(int l){
    for (int i = 0; i < alfa; ++i){
        if (V[l][i].size() == 1) {
            if (first) first = false;
            else cout << " ";
            cout << V[l][i][0];
        }
        else{
            for (int j = 0; j < V[l][i].size(); ++j){
                int index = V[l][i][j];

                if (index + l + 1 == s.size()) {
                    if (first) first = false;
                    else cout << " ";
                    cout << V[l][i][j];
                }
                else V[l+1][s[index + l + 1] - 'A'].push_back(index);
                
            }

            if (not V[l][i].empty()) rec(l+1);

        }

        V[l][i].clear();
    }
}

int main () {
    cin >> s;

    int n = s.size();

    V = vvvi(16, vvi(alfa)); 

    for (int i = 0; i < n; ++i) V[0][s[i] - 'A'].push_back(i);

    rec(0);

    cout << '.' << '\n';
}