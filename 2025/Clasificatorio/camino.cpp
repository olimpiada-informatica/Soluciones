#include <bits/stdc++.h>
#define int long long
using namespace std;
    
signed main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int dx = 0;
        int dy = 0;
        bool hn = false;
        bool hs = false;
        bool he = false;
        bool ho = false;
        int rec = 0;
        for (int i = 0; i < n; ++i) {
            char d;
            int l;
            cin >> d >> l;
            if (d == 'N') {
                if (l == -1) {
                    l = 1;
                    hn = true;
                }
                dx += l;
            }
            if (d == 'S') {
                if (l == -1) {
                    l = 1;
                    hs = true;
                }
                dx -= l;
            }
            if (d == 'E') {
                if (l == -1) {
                    l = 1;
                    he = true;
                }
                dy += l;
            }
            if (d == 'O') {
                if (l == -1) {
                    l = 1;
                    ho = true;
                }
                dy -= l;
            }
            rec += l;
        }
        rec += abs(dx)+abs(dy);
        bool pos = (dx == 0 || (dx > 0 && hs) || (dx < 0 && hn)) &&
                (dy == 0 || (dy > 0 && ho) || (dy < 0 && he));
        if (!pos) {
            cout << "-1 -1";
        }
        else {
            cout << rec << ' ';
            bool inf = (hn && hs || he && ho);
            if (inf) cout << -1;
            else cout << rec;
        }
        cout << '\n';
    }
}