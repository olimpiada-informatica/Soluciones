#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        string n;
        cin >> n;
        reverse(n.begin(), n.end());
        string a, b;
        int l = n.length();
        int carry = 0;
        for (int i=0; i < l; ++i) {
            int s = (n[i]-'0')-carry;
            if (i+1 < l && s <= 0) {
                s += 10;
                carry = 1;
            }
            else carry = 0;
            char x, y;
            if (s < 10) {
                x = s+'0';
                y = '0';
            }
            else {
                x = '9';
                y = s-9+'0';
            }
            if (!a.empty() && x == a.back()) swap(x, y);
            if (!b.empty() && y == b.back()) swap(x, y);
            a.push_back(x);
            b.push_back(y);
        }
        while ((int)a.length() > 1 && a.back() == '0') a.pop_back();
        while ((int)b.length() > 1 && b.back() == '0') b.pop_back();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        cout << a << " " << b << endl;
    }
}