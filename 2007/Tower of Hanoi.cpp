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


int suma (string& s){
    int ans = 0;

    for (int i = 0; i < s.size(); ++i){
        ans += (s[i] - '0');
    }

    return ans;
}

void divide2(string& s){
    string ans;
    int carry = 0;

    for (int i = 0; i < s.size(); ++i){

        int digit = (s[i] - '0') + 10*carry;
        carry = digit % 2;
        ans.push_back('0' + int(digit/2));
    }

    s = ans;
}

void solve(int n, string& s){
    int a = 0, b = 0, c = 0;

    for (int i = 0; i < n; ++i){

        int sum = suma(s) % 3;
        int p = (s.back() - '0') % 2;

        if (sum == 1) sum = 4;
        int mod6 = (sum + 3*p)%6;
            
        if (i % 2 == 0){
            if (mod6 == 0 or mod6 == 5) ++a;
            else if (mod6 < 3) ++b;
            else ++c;
        }
        else {
            if (mod6 == 0 or mod6 == 5) ++a;
            else if (mod6 < 3) ++c;
            else ++b;
        }
        divide2(s);
    }

    cout << a << " " << b << " " << c << endl;
}

int main (){
    int n;
    string s;

    while (cin >> n >> s){
        if (n == 0) break;
        solve(n, s);
    }
}   