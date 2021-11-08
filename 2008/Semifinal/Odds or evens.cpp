#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

int main (){
    int k;
    cin >> k;

    for (int w = 1; w <= k; ++w){
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        bool even = false;

        if (a == "pares" and b == "Bernardo") even = true;
        if (a == "nones" and b == "Ana") even = true;  

        cout << "ronda " << w << endl;
        for (int i = 0; i <= n; ++i){
            for (int j = 0; j <= n; ++j){
                if ((i + j) % 2 == 0 and even) cout << i << " " << j << endl;
                if ((i + j) % 2 == 1 and not even) cout << i << " " << j << endl;
            }
        }

        cout << endl;
    }   
}