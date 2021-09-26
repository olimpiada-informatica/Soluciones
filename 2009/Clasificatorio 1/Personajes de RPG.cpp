#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;

void update(int& y){
    y = (75 * y) % 65537;
}

int trial(int& y, int face){
    update(y);
    return (y % face) + 1;
}

int evaluate(int& y, string& dice){
    int times = dice[0] - '0';
    int face = 0;

    if (dice[2] > '2') face = dice[2] - '0';
    else face = (dice[2] - '0') * 10 + dice[3] - '0'; 

    int add = 0;
    int sign = 1;

    if (dice.size() > 4){
        if (dice[dice.size()-2] == '-') sign *= -1;
        add = dice.back() - '0';
    }

    int sum = 0;
    for (int i = 0; i < times; ++i){
        sum += trial(y, face);
    }

    sum += add * sign; 

    return max(sum, 1);
}

int main (){
    int y;
    cin >> y;

    map <string, int> M;
    int cnt = 0;

    vector <vector <string> > V(1);
    vi times(1);

    string s;
    while (getline(cin, s)){
        if (s.size() == 0) continue;
        stringstream ss(s);

        char c;
        ss >> c;

        if (c == 'R'){
            string raza;
            ss >> raza;

            M[raza] = ++cnt;
            int x;
            ss >> x;

            string atr;
            vector <string> W(2*x);
            for (int i = 0; i < 2*x; ++i) ss >> W[i];
            V.push_back(W);
            times.push_back(0);
        }
        if (c == 'P'){
            string raza;
            ss >> raza;

            if (M.find(raza) == M.end()) cout << "Raza " << raza << " no existe.\n";
            else {
                int k;
                ss >> k;

                int index = M[raza];
                
                for (int i = 0; i < k; ++i){   
                    cout << raza << " #" << ++times[index] << ":";
                    for (int j = 0; j < V[index].size(); j += 2){
                        cout << " " << V[index][j] << " ";
                        cout << evaluate(y, V[index][j+1]);
                    }
                    cout << ".\n";
                }
            }
        }
    }
}