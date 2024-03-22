#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int s, t;
        s = t = 1;
        while (t < n) {
            s = s + t;
            t = s + t;
        }
        if (s < n) {
            cout << s << endl;
        }
        else {
            cout << "OK" << endl;
        }
    }
}
