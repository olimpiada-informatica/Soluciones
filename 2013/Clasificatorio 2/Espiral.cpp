#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;


void update (int& i, int& j, int& s, int& si, int& sj, int& mi, int& mj, int& Mi, int& Mj){
    if (i == Mi and si > 0){
        --i;

        si = 0;
        if (s == 0) Mj -= 2;
        else mj += 2;

        if (s == 0) sj = -1;
        else sj = 1;

        j += sj;
    }   

    if (j == Mj and sj > 0){
        --j;

        sj = 0;
        if (s == 0) mi += 2;
        else Mi -= 2;

        if (s == 0) si = 1;
        else si = -1;

        i += si;
    }

    if (i == mi and si < 0){
        ++i;

        si = 0;
        if (s == 0) mj += 2;
        else Mj -= 2;

        if (s == 0) sj = 1;
        else sj = -1;

        j += sj;
    }

    if (j == mj and sj < 0){
        ++j;

        sj = 0;
        if (s == 0) Mi -= 2;
        else mi += 2;

        if (s == 0) si = -1;
        else si = 1;

        i += si;
    }
}

int main (){
    int f, c, s;
    string t;
    cin >> f >> c >> s >> t;

    vector <string> M(f, string(c, '.'));

    int p = 0, i = 0, j = 0, si = 0, sj = 1, mi = -1, mj = -1, Mi = f, Mj = c;
    
    if (s == 1) {
        sj = -1;
        mi = -3;
    }

    int equal = 0;
    while (mi < Mi and mj < Mj and equal < 2){
        M[i][j] = t[p];

        i += si;
        j += sj;
        ++p;

        if (p == t.size()) p = 0;
        update(i, j, s, si, sj, mi, mj, Mi, Mj);
        equal = (i == Mi) + (i == mi) + (j == mj) + (j == Mj);
    }

    for (int i = 0; i < f; ++i) cout << M[i] << endl;
}