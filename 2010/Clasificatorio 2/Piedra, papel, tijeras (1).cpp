#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef long long int ll;


int points(string& a, string& b){
    if (a == b) return 1;
    if (a == "piedra" and b == "tijeras") return 2; 
    if (a == "papel" and b == "piedra") return 2;
    if (a == "tijeras" and b == "papel") return 2;
    return 0;
}

int main (){
    int x = 0, y = 0;

    string a, b;
    while (cin >> a >> b){
        x += points(a, b);
        y += points(b, a);
    }

    cout << x << " " << y << endl;
}