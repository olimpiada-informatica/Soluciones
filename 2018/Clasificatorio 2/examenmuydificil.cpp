#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int ccc;
    cin >> ccc;
    for (int cas = 0; cas < ccc; ++cas) {
        int n;
        cin >> n;
        int res = 0;
        bool primer = true;
        int cont = 0;
        char ant;
        for (int i = 0; i < n; ++i) {
            char a;
            cin >> a;
            if (primer and a == '?') continue;
            
            if (a == '?') ++cont;
            else if (!primer) {
                ++res;
                if (ant == a) {
                    if (cont > 1) ++res;
                    cont = 0;
                } else {
                    if (cont) ++res;
                    cont = 0;
                    ant = a;
                }
            }
            else {
                ++res;
                primer = false;
                ant = a;
                cont = 0;
            }
        }
        cout << res << endl;
    }
}
