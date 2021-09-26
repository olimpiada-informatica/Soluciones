#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;

int main (){
    map <char, char> D;
    map <char, char> I;

    D['A'] = 's';
    D['B'] = 'n';
    D['C'] = 'v';
    D['D'] = 'f';
    D['E'] = 'r';
    D['F'] = 'g';
    D['G'] = 'h';
    D['H'] = 'j';
    D['I'] = 'o';
    D['J'] = 'k';
    D['K'] = 'l';
    D['N'] = 'm';
    D['O'] = 'p';
    D['Q'] = 'w';
    D['R'] = 't';
    D['S'] = 'd';
    D['T'] = 'y';
    D['U'] = 'i';
    D['V'] = 'b';
    D['W'] = 'e';
    D['X'] = 'c';
    D['Y'] = 'u';
    D['Z'] = 'x';

    I['B'] = 'v';
    I['C'] = 'x';
    I['D'] = 's';
    I['E'] = 'w';
    I['F'] = 'd';
    I['G'] = 'f';
    I['H'] = 'g';
    I['I'] = 'u';
    I['J'] = 'h';
    I['K'] = 'j';
    I['L'] = 'k';
    I['M'] = 'n';
    I['N'] = 'b';
    I['O'] = 'i';
    I['P'] = 'o';
    I['R'] = 'e';
    I['S'] = 'a';
    I['T'] = 'r';
    I['U'] = 'y';
    I['V'] = 'c';
    I['W'] = 'q';
    I['X'] = 'z';
    I['Y'] = 't';

    string s;
    while (cin >> s){
        string ans;

        for (int i = 0; i < s.size(); i += 2){
            if (s[i+1] == 'B') ans.push_back(s[i] + 'a' - 'A');
            if (s[i+1] == 'D') ans.push_back(D[s[i]]);
            if (s[i+1] == 'I') ans.push_back(I[s[i]]);
        }

        cout << ans << endl;
    }
}