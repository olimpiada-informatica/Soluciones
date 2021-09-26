#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

vector <double> V(501);

void init(){
    V[1] = 1;
    double sum = 0.5;
    
    for (int i = 2; i <= 500; ++i){
        V[i] = 1 + sum/(i-1);
        sum += (V[i] - 0.5);
    }
}


int main (){
    cout.setf(ios::fixed);
    cout.precision(4);
    init();

    int n;
    while (cin >> n) cout << V[n] << endl;
}