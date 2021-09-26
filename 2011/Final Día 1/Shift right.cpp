#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <string>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

void shift(string& s){
    s.insert(s.begin(), s.back());
    s.pop_back();
}

int main (){
    int n;
    cin >> n;

    string s;
    getline(cin, s);

    vector <vector <string> > V(n);

    for (int i = 0; i < n; ++i){
        getline(cin, s);

        stringstream ss(s);
        string word;

        if (i == n-1){
            V[0].push_back("");
            while (ss >> word){
                shift(word);
                V[0].push_back(word);
            }
            V[0][0] = V[0].back();
            V[0].pop_back();
        }
        else {
            V[i+1].push_back("");
            while (ss >> word){
                shift(word);
                V[i+1].push_back(word);
            }
            V[i+1][0] = V[i+1].back();
            V[i+1].pop_back();
        }
    }

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < V[i].size(); ++j){
            if (j > 0) cout << " ";
            cout << V[i][j];
        }
        cout << '\n';
    }
}