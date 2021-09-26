#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
 
using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;

string s, a, b;
int pos;

void spent(){
    set <char> S;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' and s[i] <= 'z') S.insert(s[i]);
    }

    for (char c: S) cout << c;
    cout << endl;
}


set <char> free(){
    if (s[pos] >= 'a' and s[pos] <= 'z') return {s[pos++]};
    if (s[pos] == '\\'){
        ++pos;
        char c = s[pos++];
        ++pos;

        set <char> ans = free();
        ans.erase(c);
        return ans;
    }
    
    ++pos;
    set <char> A = free();
    ++pos;
    set <char> B = free();

    for (char x: B) A.insert(x);
    ++pos;

    return A;
}

string expression(){
    string ans;
    int spaces = 0;

    int open = 0;

    while (true){
        if (s[pos] == ' ' and spaces == 0) return ans;
        if (s[pos] == ')' and open == 0) return ans;
        if (s[pos] == '(') {
            ++spaces;
            ++open;
        }
        if (s[pos] == ')') --open;
        if (s[pos] == ' ') --spaces;
        ans.push_back(s[pos++]);
    }
}

void substitute(char x){
    if (a[pos] >= 'a' and a[pos] <= 'z'){
        if (a[pos++] == x) cout << b;
        else cout << a[pos-1];
        return;
    }

    if (a[pos] == '\\'){
        cout << "\\";

        ++pos;
        if (a[pos] == x){
            cout << a[pos++];
            cout << a[pos++];

            cout << expression();
            return;
        }
        else {
            cout << a[pos++];
            cout << a[pos++];
            
            substitute(x);
            return;
        }
    }

    cout << "(";
    ++pos;

    substitute(x);
    cout << s[pos++];

    substitute(x);
    cout << s[pos++];
}

int main (){
    char c;

    while (cin >> c){
        getline(cin, s);

        if (c == 'G') spent();
        if (c == 'L') {
            pos = 1;
            set <char> T = free();
            for (char x: T) cout << x;
            cout << '\n';
        }
        if (c == 'S'){
            char x = s[1];
            s.push_back(' ');

            pos = 3;
            a = expression();
            ++pos;
            b = expression();

            a.push_back(' ');
            s = a;

            pos = 0;
            substitute(x);
            cout << '\n';
        }
    }
}   