#include<bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

void print(vvi ans) {
    int n = ans.size();
    int m = ans[0].size();
    int mx = 0;
    for (vi v : ans) for (int x : v) mx = max(x, mx);
    cout << mx+1 << endl;
    for (int i=0; i < n; ++i) {
        for (int j=0; j < m; ++j) {
            if (j) cout << " ";
            cout << ans[i][j]+1;
        }
        cout << endl;
    }
}

struct Vec {
    int x;
    int y;
    Vec() {

    }
    Vec (int _x, int _y) {
        x = _x; y = _y;
    }
    bool operator<(Vec v) const {
        if (x != v.x) return x < v.x;
        return y < v.y;
    }
};

using ii = Vec;
using vii = vector<ii>;

ii operator+(ii a, ii b) {
    return ii(a.x+b.x, a.y+b.y);
}

ii operator-(ii a, ii b) {
    return ii(a.x-b.x, a.y-b.y);
}

struct Tile {
    vvi rows;
    vii offsets;
    ii v1;
    ii v2;

    void iterate_over_all(function<void(int, int, int)>& pred) const {
        int l = rows.size();
        for (int i=0; i < l; ++i) {
            int lr = rows[i].size();
            for (int j=0; j < lr; ++j) {
                pred(offsets[i].x, j + offsets[i].y, rows[i][j]);
            }
        }
    }
};

bool inside(int x, int y, int n, int m) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool tile_new(const vvi& a, const Tile& t, ii offset) {
    int n = a.size();
    int m = a[0].size(); 
    bool ans = false;
    function<void(int, int, int)> f = [&] (int x, int y, int _) {
        if (inside(x+offset.x, y+offset.y, n, m) && a[x+offset.x][y+offset.y] == -1) ans = true;
    };
    t.iterate_over_all(f);
    return ans;
}

void tesellate(vvi& a, const Tile& t, ii offset) {
    int n = a.size(); 
    int m = a[0].size();
    function<void(int, int, int)> f = [&] (int x, int y, int v) {
        if (inside(x+offset.x, y+offset.y, n, m) && a[x+offset.x][y+offset.y] == -1) {
            a[x+offset.x][y+offset.y] = v;
        }
    };
    t.iterate_over_all(f);
    if (tile_new(a, t, offset+t.v1)) tesellate(a, t, offset+t.v1);
    if (tile_new(a, t, offset-t.v1)) tesellate(a, t, offset-t.v1);
    if (tile_new(a, t, offset+t.v2)) tesellate(a, t, offset+t.v2);
    if (tile_new(a, t, offset-t.v2)) tesellate(a, t, offset-t.v2);

}

vvi solve(int n, int m, int d) {
    bool transp = false;
    if (n > m) {
        swap(n, m);
        transp = true;
    }
    vvi ans = vvi(n, vi(m, -1));

    if (d <= m) {
        Tile t;
        int h = n-1;
        int w = d-2;
        int c = 0;
        vi ini_row(d);
        for (int i=0; i < d; ++i) ini_row[i] = c++;
        t.rows.push_back(ini_row);
        t.offsets.push_back(ii(0, 0));
        int off = 1;
        while (h > 0 && w > 0) {
            vi row(w);
            for (int i=0; i < w; ++i) row[i] = c++;
            t.rows.push_back(row);
            t.offsets.push_back(ii(off, off));
            h--;
            if (h > 0) {
                row = vi(w);
                for (int i=0; i < w; ++i) row[i] = c++;
                t.rows.push_back(row);
                t.offsets.push_back(ii(-off, off));
                h--;
            }
            w -= 2;
            off++;
        }
        t.v1 = ii(off-1, d-off+1);
        t.v2 = ii(-off+(1-t.rows.size()%2), d-off+(1-t.rows.size()%2));
        tesellate(ans, t, ii(0, 0));
    }
    else {
        int downr = (n-1)/2;
        int upr = downr+1;
        int c = 0;
        if (n%2) {
            for (int i=0; i < m; ++i) ans[downr][i] = c++;
            downr--;
        }
        while (downr >= 0) {
            if (upr == n) {
                int len = min(m, d-(upr-1-downr));
                int stp = max(m/2-(len)/2, 0);
                for (int i=stp; i < stp+len; ++i) {
                    ans[downr][i] = c++;
                }
            }
            else {
                int len = min(m, d-(upr-downr));
                int stp = max(m/2-(len)/2, 0);
                for (int i=stp; i < stp+len; ++i) {
                    ans[upr][i] = c++;
                    ans[downr][i] = c++;
                }
            }
            upr++;
            downr--;
        }

        vvi orians = ans;
        int ulen = 0;
        while (ans[ulen][0] == -1 || ans[ulen][m-1] == -1) ulen++;
        int row = n-ulen-1;
        for (int i=0; i < n; ++i) {
            if (ans[i][0] != -1 && ans[i][m-1] != -1) continue;
            row++;
            if (row == n) row = 0;
            int scol = m-1;
            int llen = 0;
            while (ans[i][llen] == -1) llen++;
            while (orians[row][scol] == -1) scol--;
            scol -= (llen-1);
            int col = scol;
            for (int j=0; j < m; ++j) {
                if (ans[i][j] == -1) {
                    ans[i][j] = orians[row][col];
                    col++;
                }
                else break;
            }
            col = scol-1;
            while (abs(row-i) + abs(col-(m-1)) < d) col--;
            for (int j=m-1; j > -1; --j) {
                if (ans[i][j] == -1) {
                    if (orians[row][col] == -1) {
                        row++;
                    }
                    ans[i][j] = orians[row][col];
                    col--;
                }
                else break;
            }
        }
    }

    if (transp) {
        vvi ans2(m, vi(n));
        for (int i=0; i < n; ++i) {
            for (int j=0; j < m; ++j) {
                ans2[j][i] = ans[i][j];
            }
        }
        ans = ans2;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, m, d;
        cin >> n >> m >> d;
        vvi ans = solve(n, m, d);
        print(ans);
    }
}