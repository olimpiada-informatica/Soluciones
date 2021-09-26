#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

int main (){
    int n, k;
    cin >> n >> k;

    string s(n, '.');
    vvi V(n, vi(k));

    for (int i = 0; i < n; ++i){
        cin >> s[i];

        for (int j = 0; j < k; ++j) cin >> V[i][j];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i){
        string t;
        cin >> t;

        t.push_back('-');
        int pos = 0;

        int index = 0;
        while (t[index] != '-'){
            pos = V[pos][t[index] - 'A'];
            ++index;
        }

        if (s[pos] == 'A') cout << "Ok" << '\n';
        else cout << "No" << '\n';
    }
}