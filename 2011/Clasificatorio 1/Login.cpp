#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;


bool login(string& s){
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == '_') continue;
        if (s[i] >= '0' and s[i] <= '9') continue;
        if (s[i] >= 'a' and s[i] <= 'z') continue;
        if (s[i] >= 'A' and s[i] <= 'Z') continue;

        return false;
    }
    return true;
}

bool email(string& s){
    int last = -1;
    bool punto = false;

    for (int i = 0; i < s.size(); ++i){
        if (i == 0 and s[i] == '@') return false;
        if (s[i] == '_') continue;
        if (s[i] >= '0' and s[i] <= '9') continue;
        if (s[i] >= 'a' and s[i] <= 'z') continue;
        if (s[i] >= 'A' and s[i] <= 'Z') continue;

        if (s[i] == '@'){
            if (last > -1) return false;
            else last = i;
        }
        else if (last == -1) return false;
        else if (s[i] == '.'){
            punto = true;
            if (last + 1 >= i) return false;
            else last = i;
        }
        else return false;
    }

    if (not punto) return false;
    return last < s.size() - 1;
}

int main (){
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        if (login(s)) cout << "LOGIN\n"; 
        else if (email(s)) cout << "E-MAIL\n";
        else cout << "NADA\n";
    }
}