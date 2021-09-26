#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <math.h>

using namespace std;
typedef long long int ll;

string s;
bool divis;
int i;

ll expresion();

ll factor(){
    if (s[i] >= '0' and s[i] <= '9') {
        ll number = 0;

        while (i < s.size() and s[i] >= '0' and s[i] <= '9'){
            number *= 10;
            number += s[i] - '0';
            ++i;
        }

        return number;
    }

    if (s[i] == '-') {
        ++i;
        return -factor();
    }

    ++i;
    ll ans = expresion();
    ++i;
    return ans;
}


ll expresion (){
    ll ans = factor();
    while (i < s.size() and s[i] != ')'){
        if (s[i] == '+'){
            ++i;
            ans += expresion();
        }
        else if (s[i] == '-'){
            ++i;
            ans -= expresion();
        }
        else if (s[i] == '*'){
            ++i;
            ans *= expresion();
        }
        else{
            ++i;
            ll divisor = expresion();
            if (divisor == 0) {
                divis = true;
                return 1;
            }
            ans /= divisor;
        }
    }

    return ans;
}

int main (){
    while (cin >> s){
        i = 0;
        divis = false;
        ll result = expresion();
        if (divis) cout << "DIV 0\n";
        else cout << result << '\n';
    }
}