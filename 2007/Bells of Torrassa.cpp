#include <iostream>
#include <vector>

using namespace std;
typedef vector <int> vi;


int main () {
    int h, m;
    while (cin >> h >> m){
        if (m == 0){
            for (int i = 0; i < 4; ++i) {
                if (i > 0) cout << " ";
                cout << "ding";
            }
            if (h == 0) h = 12;
            if (h > 12) h -= 12;

            for (int i = 0; i < h; ++i) cout << " dong";
            cout << endl;
        }
        else if (m == 15 or m == 30 or m == 45){
            for (int i = 0; i < m/15; ++i) {
                if (i > 0) cout << " ";
                cout << "ding";
            }
            cout << endl;
        }

        else{
            while (m != 60 and m != 15 and m != 30 and m != 45) ++m;
            if (m == 60){
                m = 0;
                ++h;
                if (h == 24) h = 0;
            }

            cout << "silence until ";
            if (h < 10) cout << "0";
            cout << h << ":";
            if (m < 10) cout << "0";
            cout << m << endl;
        }
    }
}