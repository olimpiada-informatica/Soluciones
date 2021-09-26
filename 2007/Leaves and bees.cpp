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

int main (){
    int F, L, m;
    cin >> F >> L >> m;

    vector <string> V(m+2, string(82, ' '));

    for (int i = 1; i <= m; ++i){
        string s;
        if (i == 1) getline(cin, s);
        getline(cin, s);

        for (int j = 0; j < s.size(); ++j) V[i][j] = s[j];
    }
    
    int total = 0, plants = 0;

    for (int i = 1; i <= m; ++i){
        if (V[i][0] != '-') continue;

        int leaves = 0;
        bool flower = false;

        for (int k = 0; k < 82; ++k){
            if (V[i][k] == ' ') k = 100;
            else if (V[i][k] == 'x'){
                flower = true;

                for (int x = i-1; x <= i+1; ++x){
                    for (int y = k; y <= k+2; ++y){
                        if (V[x][y] != 'x') flower = false;
                    }
                }
                k = 100;
            }
            else if (V[i][k] == 'B') k = 100;
            else if (V[i][k] == '-'){
                if (V[i-1][k] == 'b') ++leaves;
                if (V[i+1][k] == 'P') ++leaves;
            }
            else k = 100;
        }

        if (flower){
            if (leaves * L > F) {
                total += leaves * L - F;
                ++plants;
            }
        }
    }

    cout << total << endl << plants << endl;
}   