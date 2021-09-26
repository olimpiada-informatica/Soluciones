#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <sstream>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;

vi V, P;
const int alfa = 'z' - 'a' + 1;

int pos;

void cifrar(string& word){
    for (int i = 0; i < word.size(); ++i){
        if (word[i] < 'A' or word[i] > 'z') continue;
        if (word[i] > 'Z' and word[i] < 'a') continue;

        ++pos;
        if (pos == P.size()) pos = 0;
        int key = P[pos];

        if (word[i] > 'Z') word[i] = 'a' + (((word[i] - 'a' + V[key]) % alfa) + alfa)%alfa;
        else word[i] = 'A' + (((word[i] - 'A' + V[key]) % alfa) + alfa)%alfa;
    }

    cout << word << '\n';
}


void descifrar(string& word){
    for (int i = 0; i < word.size(); ++i){
        if (word[i] < 'A' or word[i] > 'z') continue;
        if (word[i] > 'Z' and word[i] < 'a') continue;

        ++pos;
        if (pos == P.size()) pos = 0;
        int key = P[pos];


        if (word[i] > 'Z') word[i] = 'a' + (((word[i] - 'a' - V[key]) % alfa) + alfa)%alfa;
        else word[i] = 'A' + (((word[i] - 'A' - V[key]) % alfa) + alfa)%alfa;
    }

    cout << word << '\n';
}



int main (){
    int C;
    bool first = true;

    while (cin >> C){
        if (C < 1) break;

        if (first) first = false;
        else cout << '\n';

        pos = -1;
        V = vi(C);
        for (int i = 0; i < C; ++i) cin >> V[i];

        P = vi();

        string s;
        getline(cin, s);
        getline(cin, s);

        stringstream ss(s);
        int x;
        while (ss >> x) P.push_back(x-1);

        string operation;
        getline(cin, operation);

        string word;
        getline(cin, word);
        while (word != "."){
            if (operation == "CIFRAR") cifrar(word); 
            else descifrar(word);
            getline(cin, word);
        }
    }
}