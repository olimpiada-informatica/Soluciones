#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef long long int ll;

int main (){
    string s;
    while (getline(cin, s)){
        if (s == "---") break;

        for (int i = 0; i < s.size(); ++i){
            if (s[i] < 'a' or s[i] > 'z') continue;

            if (i == 0) s[i] += 'A' - 'a';
            else if (s[i-1] == ' ') s[i] += 'A' - 'a';
        }

        cout << s << endl;
    }
}