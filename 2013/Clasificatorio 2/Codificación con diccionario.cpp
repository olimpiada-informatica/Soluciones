#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <sstream>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef long long int ll;

int main (){
    string s;
    getline(cin, s);

    if (s == "ORIGINAL"){
        cout << "CODIFICADO" << endl;

        map <string, int> M;

        int cnt = 0;

        string t;
        while (getline(cin, t)){
            stringstream ss(t);

            string w;
            bool first = true;
            while (ss >> w){
                if (first) first = false;
                else cout << " ";

                if (M.find(w) == M.end()){
                    M[w] = cnt++;
                    cout << w;
                }
                else cout << M[w];
            }

            cout << endl;
        }
    }

    else {
        cout << "ORIGINAL" << endl;

        vector <string> V;

        string t;
        while (getline(cin, t)){
            stringstream ss(t);

            string w;
            bool first = true;
            while (ss >> w){
                if (first) first = false;
                else cout << " ";

                if (w[0] >= '0' and w[0] <= '9'){
                    int index = stoi(w);
                    cout << V[index];
                }
                else {
                    V.push_back(w);
                    cout << w;
                }
            }

            cout << endl;
        }
    }
}