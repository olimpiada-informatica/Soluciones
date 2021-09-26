#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

int main (){
    string s;
    while (getline(cin, s)){
        reverse(s.begin(), s.end());
        cout << s << '\n';
    }
}