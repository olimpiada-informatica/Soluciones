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
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvvvi> vvvvvi;

const int alfa = 'z' - 'a' + 1;

vector <string> keyboard = {"QWERT*YUIOP", "ASDFG*HJKL*", "ZXCVB*NM***"};
vector <int> X(alfa), Y(alfa);

vvvvvi dp;

void init(){
    for (int i = 0; i < keyboard.size(); ++i){
        for (int j = 0; j < keyboard[0].size(); ++j){
            if (keyboard[i][j] == '*') continue;
            int letter = keyboard[i][j] - 'A';

            X[letter] = i;
            Y[letter] = j;
        }
    }
}

int rec(int x1, int y1, int x2, int y2, int pos, string& s){
    if (pos == s.size()) return 0;

    int& ans = dp[x1][y1][x2][y2][pos];
    if (ans != -1) return ans;

    int x = X[s[pos] - 'A'], y = Y[s[pos] - 'A'];

    return ans = min(abs(x1-x) + abs(y1-y) + rec(x, y, x2, y2, pos+1, s), abs(x2-x) + abs(y2-y) + rec(x1, y1, x, y, pos+1, s));
}

int main (){
    int k;
    cin >> k;

    init();

    string s;
    if (k == 1){
        while (cin >> s){
            int x1 = 0, y1 = 0, x2 = 0, y2 = 6;
            int total = 0;

            for (int i = 0; i < s.size(); ++i){
                int x = X[s[i] - 'A'], y = Y[s[i] - 'A'];

                if (y > 5) {
                    total += abs(x - x2) + abs(y - y2);
                    x2 = x; y2 = y;
                }
                else {
                    total += abs(x - x1) + abs(y - y1);
                    x1 = x; y1 = y;
                }
            }

            cout << total + s.size() << '\n';
        }
    }

    else {
        while (cin >> s){
            dp = vvvvvi(3, vvvvi(11, vvvi(3, vvi(11, vi(s.size() + 1, -1)))));
            cout << s.size() + rec(0, 0, 0, 6, 0, s) << '\n';
        }
    }
}