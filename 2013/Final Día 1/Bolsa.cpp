#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;

vector <string> busines, sequence;
vi V;

void draw(int h, int v){
    vector <string> M(v+1, string(h, ' '));

    h -= (2 + sequence[0].size());

    for (int i = 0; i < busines.size(); ++i){
        string s = busines[i];
        string t = sequence[i];
        int m = V[i];

        for (int j = 0; j < s.size(); ++j) M[v-m][h-j-1] = s[s.size()-j-1];
        for (int j = 0; j < t.size(); ++j) {
            if (t[j] == 'U'){
                if (M[v-m][h+j+1] == '\\') M[v-m][h+j+1] = 'X';
                else if (M[v-m][h+j+1] != 'X') M[v-m][h+j+1] = '/';
                ++m;
            }
            else {
                if (M[v-m+1][h+j+1] == '/') M[v-m+1][h+j+1] = 'X';
                else if (M[v-m+1][h+j+1] != 'X') M[v-m+1][h+j+1] = '\\';
                --m;
            }
        }
    }

    M[v][h-1] = '0';
    for (int i = h; i < M[0].size(); ++i) M[v][i] = '-';
    for (int i = 0; i < M.size()-1; ++i) M[i][h] = M[i].back() = '|';

    for (int i = 0; i < M.size(); ++i) cout << M[i] << endl;

}


int main (){
    string a, b;
    int n;

    int h = 0, v = 0;

    while (cin >> a >> n >> b){
        busines.push_back(a);
        sequence.push_back(b);
        V.push_back(n);

        h = max(h, int(a.size() + 2 + b.size()));
        v = max(v, n);
        for (int i = 0; i < b.size(); ++i){
            if (b[i] == 'U') {
                v = max(v, n);
                ++n;
            }
            else {
                --n;
                v = max(v, n);
            }
        }
    }
    draw(h, v);
}