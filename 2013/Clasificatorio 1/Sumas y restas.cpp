#include <iostream>
#include <vector>

using namespace std;
typedef long long int ll;
typedef pair <int, int>  ii;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ii> vii;

int m, p;
string s;
vector <vector <int> > memo;

int main (){
    while (cin >> s >> m){
        vector < vector <bool> > reachable (s.length(), vector <bool> (1801, false));
        int minim = 900 - (s[0]-'0');
        int maxim = 900 + (s[0]-'0');
        reachable[0][minim] = true;
        reachable[0][maxim] = true;

        for  (int i = 1; i < s.size(); ++i){
            for (int j = minim; j <= maxim; ++j){
                if (reachable[i-1][j]){
                    reachable[i][j+(s[i]-'0')] = true;
                    reachable[i][j-(s[i]-'0')] = true;
                }
            }
            maxim += (s[i]-'0');
            minim -= (s[i]-'0');
        }

        if (reachable[s.size()-1][900+m]) cout << "si" << endl;
        else cout << "no" << endl;
    }
}