#include<bits/stdc++.h>

using namespace std;

bool ask(int c, int d) {
    cout << "? " << c << " " << d << endl;
    int ans;
    cin >> ans;
    if (ans == -1) exit(0);
    return ans;
}

int main() {
    const int MAX_A = 100;
    int low = 1;
    int high = MAX_A+1;
    while(low+1 < high) {
        int mid = (low+high)/2;
        if (ask(mid, mid)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    int b = low;
    high = MAX_A+1;
    while(low+1 < high) {
        int mid = (low+high)/2;
        if (ask(mid, b)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    int a = low;
    cout << "! " << a << " " << b << endl;
}
