#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;

string n1 = {'O', 'I', '.', '.', '.', 'S', '.', '.', '.', '.'};
string n2 = {'O', 'I', '.', 'E', 'H', 'S', '.', 'L', '.', '.'};

set <string> S;

void number(string& s, int h, int m){
    int h1 = h/10, h2 = h%10, m1 = m/10, m2 = m%10;

    if (s == "STD"){
        if (n1[h1] == '.') return;
        if (n1[h2] == '.') return;
        if (n1[m1] == '.') return;
        if (n1[m2] == '.') return;
        

        S.insert({n1[h1], n1[h2], n1[m1], n1[m2]});
    }   
    else{
        if (n2[h1] == '.') return;
        if (n2[h2] == '.') return;
        if (n2[m1] == '.') return;
        if (n2[m2] == '.') return;
        
        S.insert({n2[m2], n2[m1], n2[h2], n2[h1]});
    }
}

int main (){
    string s;
    cin >> s;
    char c;

    int h1, m1, h2, m2;
    cin >> h1 >> c >> m1 >> h2 >> c >> m2;

    while (h1 != h2 or m1 != m2){
        number(s, h1, m1);
        ++m1;
        if (m1 == 60){
            m1 = 0;
            ++h1;
            if (h1 == 24) h1 = 0;
        }
    }

    number(s, h2, m2);

    for (string x: S) cout << x << '\n';
}