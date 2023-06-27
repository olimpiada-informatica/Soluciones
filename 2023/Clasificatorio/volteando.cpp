#include<bits/stdc++.h>

using namespace std;

int ask(int i) {
    cout << "? " << i+1 << endl;
    char c;
    cin >> c;
    if (c == '>') return 1;
    else if (c == '=') return 0;
    else if (c == '<') return -1;
    else exit(0);
}
void answer(int x) {
    cout << "! " << x+1 << endl;
    char c;
    cin >> c;
    if (c == '-') exit(0);
}
int solve(int l, int r, int xp, int pt) {

    if (l == r+1) {
        return r;
    }
    if (l == r) {
        if (ask(l) != pt) return l;
        return l-1;
    }

    int mid = (l+r+1)/2;
    int res = ask(mid);
    int nxp = pt*res;
    int npt = xp*nxp*pt;
    int s;
    if (nxp == 1) s = solve(l, mid-1, nxp, npt);
    else s = solve(mid+1, r, nxp, npt);
    if (xp != nxp) {
        if (nxp == 1) s = l + (mid-1 - l) -(s-l) - 1;
        else s = mid+1 + (r-mid-1)-(s-mid-1) - 1;
    }
    return s;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int r = ask(n/2);
        if (r == 1) {
            answer(solve(0, n/2-1, 1, 1)+1);
        }
        else if (r == -1) {
            answer(solve(n/2+1, n-1, -1, 1));
        }
        else {
            answer(n/2);
        }
    }
}