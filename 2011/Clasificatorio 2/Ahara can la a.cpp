#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
#include <time.h> 

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

bool vocal(char c){
    return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
}

string change(string s, char c){
    for (int i = 0; i < s.size(); ++i){
        if (vocal(s[i])) s[i] = c;
    }

    return s;
}


int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        cout << change(s, 'a') << ',';
        cout << change(s, 'e') << ',';
        cout << change(s, 'i') << ',';
        cout << change(s, 'o') << ',';
        cout << change(s, 'u') << '.' << '\n';
    }
}   