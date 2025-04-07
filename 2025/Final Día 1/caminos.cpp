#include<bits/stdc++.h>

using namespace std;

void move(int& i, int& j, char c) {
    if (c == 'U') i--;
    if (c == 'D') i++;
    if (c == 'L') j--;
    if (c == 'R') j++;
}


void solve() {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i=0; i < n; ++i) cin >> v[i];

    int ans1;
    int ans2;
    char ans3;

    auto is_good = [&] () {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int i = 0;
        int j = 0;
        int cnt = 0;
        while (0 <= i && i < n && 0 <= j && j < n) {
            if (visited[i][j]) break;
            visited[i][j] = true;
            move(i, j, v[i][j]);
            cnt++;
        }
        return cnt == n*n && i == n-1 && j == 0;
    };

    auto try_cell = [&] (int i, int j) {
        cerr << "try_cell " << i << " " << j << endl; 
        char p = v[i][j];
        v[i][j] = 'L';
        if(is_good()) {ans1 = i; ans2 = j; ans3 = v[i][j];}
        v[i][j] = 'R';
        if(is_good()) {ans1 = i; ans2 = j; ans3 = v[i][j];}
        v[i][j] = 'U';
        if(is_good()) {ans1 = i; ans2 = j; ans3 = v[i][j];}
        v[i][j] = 'D';
        if(is_good()) {ans1 = i; ans2 = j; ans3 = v[i][j];}
        v[i][j] = p;
    };

    vector<vector<pair<int, int>>> rev(n, vector<pair<int,int>>(n, {-1, -1}));

    for(int i=0; i < n; ++i) {
        for (int j=0; j < n; ++j) {
            if (v[i][j] == 'X') continue;
            int ni = i;
            int nj = j;
            move(ni, nj, v[i][j]);
            if (!(0 <= ni && ni < n && 0 <= nj && nj < n)) {
                try_cell(i, j);
            }
            else {
                rev[ni][nj] = make_pair(i, j);
            }
        }
    }
    rev[0][0] = make_pair(0, 0);
    for(int i=0; i < n; ++i) {
        for (int j=0; j < n; ++j) {
            if (v[i][j] == 'X') continue;
            int ni = i;
            int nj = j;
            move(ni, nj, v[i][j]);
            if (!(0 <= ni && ni < n && 0 <= nj && nj < n)) {
                try_cell(i, j);
            }
            else {
                if (rev[ni][nj] != make_pair(i, j)) {
                    try_cell(i, j);
                    try_cell(rev[ni][nj].first, rev[ni][nj].second);
                }
            }
        }
    }

    cout << ans1+1 << " " << ans2+1 << " " << ans3 << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
}