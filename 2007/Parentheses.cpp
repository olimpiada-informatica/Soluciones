#include <iostream>

using namespace std;

int pos;
string s;

bool correct(){
    if (pos == s.size() - 1) return false;

    if (s[pos] == '('){
        ++pos;
        while (pos < s.size() and s[pos] != ')'){
            if (not correct()) return false;
        }

        if (pos == s.size()) return false;
        ++pos;
        return true;
    }

    if (s[pos] == '['){
        ++pos;
        while (pos < s.size() and s[pos] != ']'){
            if (not correct()) return false;
        }

        if (pos == s.size()) return false;
        ++pos;
        return true;
    }

    return false;
}


int main () {
    while (cin >> s){
        pos = 0;
        bool possible = true;

        while (possible and pos < s.size()){
            if (not correct()) possible = false;
        }

        if (possible) cout << "correct" << endl;
        else cout << "incorrect" << endl;
    }
}