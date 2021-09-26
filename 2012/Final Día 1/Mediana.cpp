#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvvvi> vvvvvi;

int main (){
    set <string> A, B;
    string s;

    while (cin >> s){
        if (s == "FIN") break;

        if (B.empty()) B.insert(s);
        else if (*B.begin() > s) A.insert(s);
        else B.insert(s);

        if (B.size() > 2 + A.size()){
            A.insert(*B.begin());
            B.erase(B.begin());
        }

        if (A.size() >= B.size()) {
            auto it = A.end();
            advance(it, -1);

            B.insert(*it);
            A.erase(it);
        }

        cout << *B.begin() << '\n';
    }
}