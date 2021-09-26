#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

const int alfa = 'z' - 'a' + 1;

int main (){
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;

        vector <int> times(alfa, 0);
        for (int i = 0; i < s.size(); ++i) ++times[s[i]-'a'];

        int odds = 0;
        for (int i = 0; i < alfa; ++i) {
            if (times[i] % 2 == 1) ++odds;
        }

        if (odds > 1) cout << "NO PALINDROME" << endl;
        else {
            for (int i = 0; i < alfa; ++i){
                for (int j = 0; j < times[i]/2; ++j) cout << char('a' + i);
            }

            for (int i = 0; i < alfa; ++i){
                if (times[i] % 2 == 1) cout << char('a' + i);
            }

            for (int i = alfa-1; i >= 0; --i){
                for (int j = 0; j < times[i]/2; ++j) cout << char('a' + i);
            }

            cout << endl;
        } 
    }
}