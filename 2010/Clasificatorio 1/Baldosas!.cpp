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

vi fib(51, 0);
vi A(51, 0);
vi B(51, 0);

void init(){
    fib[0] = 1;
    fib[1] = 1;

    for (int i = 2; i < 51; ++i) fib[i] = fib[i-1] + fib[i-2];

    A[0] = 1;
    B[0] = 2;

    for (int i = 2; i < 51; i += 2) {
        A[i] = A[i-2] + B[i-2];
        B[i] = 2*A[i] + B[i-2];
    }
}

int main (){
    init();

    int f, c;
    while (cin >> f >> c){
        if (f == 1){
            if (c % 2 == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (f == 2) cout << fib[c] << '\n';
        else {
            if (c % 2 == 0) cout << A[c] << '\n';
            else cout << 0 << '\n';
        }
    }
}