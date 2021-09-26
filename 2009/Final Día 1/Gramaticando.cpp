#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
 
using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
 
const int alfa = 'z' - 'a' + 1;

vvvi V(alfa);

vvi dp(alfa, vi(101, -1));
vector <bool> presente(alfa, false);
int rec(int conj, int l);

void translate(int p, string& prod){
    int chars = 0;
    vi T(alfa, 0);

    for (int i = 0; i < prod.size(); ++i){
        if (prod[i] < 'A' or prod[i] > 'Z') ++chars;
        else ++T[prod[i] - 'A'];
    }

    vi conjuntos = {chars};
    
    for (int i = 0; i < alfa; ++i){
        for (int j = 0; j < T[i]; ++j) conjuntos.push_back(i);
    }

    V[p].push_back(conjuntos);
}

void proceed(string& s){
    stringstream ss(s);

    char conjunto;
    ss >> conjunto;

    int p = conjunto - 'A';
    presente[p] = true;

    string prod;
    ss >> prod;

    while (ss >> prod) translate(p, prod);
}

int tryall(int conj, int i, int j, int l){
    int m = V[conj][i].size();

    if (l < m - j) return 0;
    if (j == m) return l == 0;
        

    int ans = 0;
    int tope = l + 1 + j - m;

    for (int k = 1; k <= tope; ++k){
        int elem = rec(V[conj][i][j], k);
        if (elem == 0) continue;

        ans += elem * tryall(conj, i, j + 1, l - k);
    }

    return ans;
}

int rec(int conj, int l){
    if (l <= 0) return 0;
    if (not presente[conj]) return 0;

    int& ans = dp[conj][l];
    if (ans != -1) return ans;

    ans = 0;

    for (int i = 0; i < V[conj].size(); ++i){
        int truel = l - V[conj][i][0];
        
        ans += tryall(conj, i, 1, truel);
    }

    return ans;
}


int main(){
    string s;
    getline(cin, s);

    while (s[0] != '-'){
        proceed(s);
        getline(cin, s);
    }
    
    char conjunto;
    int longitud;

    while (cin >> conjunto >> longitud){
        int p = conjunto - 'A';
        cout << rec(p, longitud) << '\n';
    }
}