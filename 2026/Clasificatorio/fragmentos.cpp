#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct SegTree {
    vector<int> st, push, sz;
    int t;
    void init(int n) {
        t = Get(n);
        st.assign(2*t, 0);
        push.assign(2*t, 0);
        sz.assign(2*t, 0);
        for (int i = 0; i < t; i++) sz[i+t] = 1;
        for (int i = t-1; i >= 1; i--) sz[i] = sz[2*i] + sz[2*i+1];
    }
    int Get(int x) {
        int y = 0;
        while ((1LL << y) < x) y++;
        return (1LL << y);
    }
    SegTree(int n) {
        init(n);
    }
    void p(int k) {
        if (k >= t || push[k] == 0) 
            return;
        push[2*k] ^= push[k];
        push[2*k+1] ^= push[k];
        if (push[k]) {
			st[2*k] = sz[2*k] - st[2*k];
			st[2*k+1] = sz[2*k+1] - st[2*k+1];
		}
        push[k] = 0;
    }
    void Upd(int a, int b, int x, int y, int k, int val = 1) {
        p(k);
        if (b < x or a > y) return;
        if (a <= x and y <= b) {
            push[k] ^= val;
            if (val)
				st[k] = sz[k]-st[k];
            return;
        }
        
        int d = (x+y)/2;
        Upd(a, b, x, d, 2*k, val);
        Upd(a, b, d+1, y, 2*k+1, val);
        st[k] = st[2*k] + st[2*k+1];
    }
};

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	int it = 0;
	map<int, int> biy;
	for (auto x : a) biy[x] = it++;
	for (auto &x : a) x = biy[x];
	vector<int> nxt(n);
	map<int, int> last;
	for (int i = n-1; i >= 0; i--) {
		if (!last.count(a[i])) nxt[i] = n;
		else nxt[i] = last[a[i]];
		last[a[i]] = i;
	}
	
	int ans = 0;
	SegTree st = SegTree(n);
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (!s.count(a[i])) st.Upd(i, n-1, 0, st.t-1, 1);
		s.insert(a[i]);
	}
	for (int i = 0; i < n; i++) {
		ans += st.st[1];
		st.Upd(i, n-1, 0, st.t-1, 1);
		st.Upd(nxt[i], n-1, 0, st.t-1, 1);
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T; cin >> T; while (T--) solve();
}
