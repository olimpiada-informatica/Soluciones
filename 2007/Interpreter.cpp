#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <string>
#include <sstream>
 
using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;

int main (){
    vector <int> var(100, 1);
    vector <string> commands;

    string command;
    while (getline(cin, command)) commands.push_back(command);

    int pos = 0;
    while (pos < commands.size()){
        stringstream ss(commands[pos]);

        int number;
        ss >> number;

        string s;
        ss >> s;

        ++pos;

             if (s == "stop") break;
        else if (s == "endl") cout << endl;
        else if (s == "prin"){
            int i; ss >> i;
            cout << " " << var[i];
        }   
        else if (s == "stor"){
            int i, v;
            ss >> i >> v;
            var[i] = v;
        }
        else if (s == "copy"){
            int i, j;
            ss >> i >> j;
            var[i] = var[j];
        }
        else if (s == "acum"){
            int i, j;
            ss >> i >> j;
            var[i] += var[j];
        }
        else if (s == "subs"){
            int i, j;
            ss >> i >> j;
            var[i] -= var[j];
        }
        else if (s == "prod"){
            int i, j;
            ss >> i >> j;
            var[i] *= var[j];
        }
        else if (s == "goto"){
            int l; ss >> l;
            pos = l;
        }   
        else if (s == "jzer"){
            int i, l;
            ss >> i >> l;
            if (var[i] == 0) pos = l;
        }  
        else if (s == "jneg"){
            int i, l;
            ss >> i >> l;
            if (var[i] < 0) pos = l;
        } 
    }
}   