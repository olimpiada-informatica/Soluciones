#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<pair<int,int>> p(n);
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            p[i] = make_pair(a, b);
        }

        bool puede = true;
        int mx = p[0].first + 1;
        for(int i = 0; i < n && puede; i++) {
            if(mx > p[i].first) {
                mx = max(mx, p[i].first + p[i].second);
            } else {
                puede = false;
            }
        }

        if(!puede) {
            cout << "Pep" << '\n';    
            continue;
        }

        puede = true;
        mx = p[0].first + p[0].second;
        pair<int,int> mxs = {p[1].first + p[1].second, -1};    
        for(int i = 2; i < n && puede; i++) {
            if(mxs.second > p[i].first || mx > p[i].first) {
                if(p[i].first + p[i].second > mxs.first) {
                    mxs.second = mxs.first;
                    mxs.first = p[i].first + p[i].second;
                } else if(p[i].first + p[i].second > mxs.second) {
                    mxs.second = p[i].first + p[i].second;
                }
            } else {
                puede = false;
            }
        }

        if(!puede) {
            cout << "Ivet" << '\n';
        } else {
            cout << "Cesc" << '\n';
        }
    }

    return 0;
}
