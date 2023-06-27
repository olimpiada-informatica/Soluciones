#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int f, a, n;
        cin >> f >> a >> n;
        int res = (n-1)%(2*a);
        if (a == 1) {
            cout << "AMBOS" << endl;
        }
        else if(res == 0 || res == 2*a-1) {
            cout << "VENTANA" << endl;
        }
        else if(res == a-1 || res == a) {
            cout << "PASILLO" << endl;
        }
        else {
            cout << ":(" << endl;
        }
    }
}