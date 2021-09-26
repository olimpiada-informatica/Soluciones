#include <iostream>
using namespace std;

int main () {
   int f, c;
   cin >> f >> c;
   f = f - 1;
   c = c - 1;

    for (int i = 0; i <= f; ++i){
        for (int h = 0; h <= c; ++h){
            if (i <= h and i <= c - h) {
                    if (i <= f-i) cout << i;
                    else cout << f - i;
            }
            if (i <= h and i > c - h)  {
                    if (c - h <= f - i) cout << c - h;
                    else cout << f - i;

            }
            if (h < i and h <= f - i) {
                    if (h <= c - h) cout << h;
                    else cout << c - h;
            }
            if (h < i and h > f - i) {
                    if (c - h <= f - i) cout << c - h;
                    else cout << f - i;

            }
        }
        cout << endl;
    }
}