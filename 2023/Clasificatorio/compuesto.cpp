#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i=0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << 2*i+1;
    }
    cout << endl;
}