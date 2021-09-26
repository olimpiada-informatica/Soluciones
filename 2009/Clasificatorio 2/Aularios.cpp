#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

int main(){
    string s;
    cin >> s;

    if (s[0] < 'A' or s[0] > 'D' or s[1] < '1' or s[1] > '6') cout << '?' << '\n';
    else {
        if (s[0] < 'D') cout << char(s[0] + 1) << s[1] << '\n';
        else cout << "--\n";
        if (s[1] < '6') cout << s[0] << char(s[1] + 1) << '\n';
        else cout << "--\n";
        if (s[0] > 'A') cout << char(s[0] - 1) << s[1] << '\n';
        else cout << "--\n";
        if (s[1] > '1') cout << s[0] << char(s[1] - 1) << '\n';
        else cout << "--\n";
    }
}