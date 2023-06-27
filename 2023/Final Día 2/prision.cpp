#include<bits/stdc++.h>

using namespace std;

int ask(int i) {
    cout << "? " << i << endl;
    int r;
    cin >> r;
    if (r < 0) exit(0);
    return r;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int p2 = 1;
        while(2*p2 <= n) p2 *= 2;
        int ans = ask(0)|ask(n-1)|ask(p2-1)|ask(n-p2);
        cout << "! " << ans << endl;
        char c;
        cin >> c;
        if (c == '-') exit(0);
    }
}