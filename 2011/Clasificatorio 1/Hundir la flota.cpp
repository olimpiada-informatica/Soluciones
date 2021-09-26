#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
#include <string> 
#include <sstream> 

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> ii;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

int main() {
    vector <string> M(11, string(11, '.'));
    M[0][0] = ' ';
    for (int i = 0; i <= 9; ++i) M[0][i+1] = '0' + i;
    for (int i = 0; i <= 9; ++i) M[i+1][0] = 'A' + i;
    M.push_back("-----------");
    
    vector <string> V(10, string(10, '.'));
    for (int i = 5; i >= 2; --i){
        string s;
        getline(cin, s);

        stringstream ss(s);
        string barco;

        while(ss >> barco){
            int x = barco[0] - 'A';
            int y = barco[1] - '0';

            if (barco[2] == 'h') {
                for (int k = 0; k < i; ++k) V[x][y+k] = 'X';
            }
            if (barco[2] == 'v') {
                for (int k = 0; k < i; ++k) V[x+k][y] = 'X';
            }
        }
    }

    string s;
    while (getline(cin, s)){
        string disparo;
        stringstream ss(s);

        while (ss >> disparo){
            int x = disparo[0] - 'A';
            int y = disparo[1] - '0';

            if (V[x][y] == '.') M[x+1][y+1] = '=';
            else M[x+1][y+1] = 'X';
        }

        for (int i = 0; i < M.size(); ++i) cout << M[i] << '\n';
    }
}   