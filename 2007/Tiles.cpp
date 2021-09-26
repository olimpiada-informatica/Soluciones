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

int a, b, f, c;
bool possible = false;

vvi pieces;
vvi follow;

void print(){
    possible = true;

    vector <string> M(f, string(c, '.'));
    for (int i = 0; i < pieces.size(); ++i){
        for (int x = pieces[i][0]; x < pieces[i][2]; ++x){
            for (int y = pieces[i][1]; y < pieces[i][3]; ++y){
                M[x][y] = 'A' + i;
            }
        }
    }

    for (int i = 0; i < M.size(); ++i) cout << M[i] << '\n';
}

bool fits(int x, int y, int v, int h){
    if (x + v > f or y + h > c) return false;

    for (int j = y; j < y + h; ++j){
        if (follow[x][j] != 0) return false;
    }
    return true;
}

void fill(int x,int y, int v, int h, int amount){
    for (int i = x; i < x + v; ++i){
        follow[i][y] = amount;
    }
}

void rec (int x, int y, char C){
    if (possible) return;
    if (y == c) {
        ++x;
        y = 0;
    }

    if (x == f) {
        print();
        return;
    }

    if (follow[x][y] != 0) {
        rec(x, y + follow[x][y], C
            );
        return;
    }


    if (fits(x, y, a, b)){
        pieces[C-'A'] = {x, y, x+a, y+b};
        fill(x, y, a, b, b);
        rec(x, y + b, C+1);
        if (possible) return;
        fill(x, y, a, b, 0);
    }
    if (fits(x, y, b, a)){
        pieces[C-'A'] = {x, y, x+b, y+a};
        fill(x, y, b, a, a);
        rec(x, y + a, C+1);
        if (possible) return;
        fill(x, y, b, a, 0);
    }
}

int main (){
    bool first = true;

    while (cin >> a >> b >> f >> c){
        if (first) first = false;
        else cout << '\n';

        if (a > b) swap(a, b);

        if (f*c/(a*b) > 26) cout << "!!!" << '\n';
        else if (f*c % (a*b) != 0) cout << "!!!" << '\n';
        else {
            int div = f*c/(a*b);
            pieces = vvi(div, vi(4));

            follow = vvi(f, vi(c, 0));
            possible = false;

            rec(0, 0, 'A');
            if (not possible) cout << "!!!" << '\n';
        }
    }
}   