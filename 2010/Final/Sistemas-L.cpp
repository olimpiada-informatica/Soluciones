#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <map>

using namespace std;
typedef long long int ll;

map <char, int> M;
vector <string> repl;
vector <string> operation;

string change(string& s){
    string ans = "";
    for (int i = 0; i < s.size(); ++i){
        ans += repl[M[s[i]]];
    }

    return ans;
}

int main (){
    string s;
    cin >> s;

    int n, k;
    cin >> n >> k;

    repl = vector <string>(n);
    operation = vector <string>(n);

    string smth;
    getline(cin, smth);

    for (int i = 0; i < n; ++i){
        getline(cin, smth);
        char c;

        stringstream ss(smth);
        ss >> c;

        M[c] = i;
        string rep;
        ss >> rep;

        string op = "";
        string a;

        while (ss >> a){
            if (not op.empty()) op.push_back(' ');
            op += a;
        }

        repl[i] = rep;
        operation[i] = op;
    }

    for (int i = 0; i < k; ++i){
        s = change(s);
    }

    cout << "%!PS\n";
    cout << "newpath 297.5 421 moveto\n";

    for (int i = 0; i < s.size(); ++i){
        cout << operation[M[s[i]]] << '\n';
    }

    cout << "2 setlinewidth stroke showpage\n";
}