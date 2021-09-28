#include<bits/stdc++.h>

using namespace std;


int n, m;

set<int> pos;
map<int, char> mem;

const int LEL = 5;


char ask(int y) {
	if(mem.find(y) == mem.end()) {
		if(y < 0) {
			mem[y] = '<';
		}
		else if(y >= n) {
			mem[y] = '>';
		}
		else {
			cout << "? " << y << endl;
		    char x;
			cin >> x;
			if(x == '-') exit(0);
			mem[y] = x;
		}
	}
	return mem[y];
}

void register_pos(int x, int dir);

bool linear_exploration(int l, int r, int dir) {
	if(l > r) return linear_exploration(r, l, dir);

	cerr << "linear_exploration(" << l << ", " << r << ", " << dir << ") " << endl;

	bool found = false;

	for(int i=l; i < r; ++i) {
		if(ask(i) == '<' && ask(i+1) == '>') {
			register_pos(i, dir);
			found = true;
		}
	}
	return found;
}

void explore(int x, int dir) {

	cerr << "explore(" << x << ", " << dir << ")" << endl;

	if(linear_exploration(x, x+LEL*dir, dir)) return;
	if(x+LEL*dir < -1 || x+LEL*dir > n) return;

	int piv = x+dir;
	int exp = 0;
	char comp = (dir > 0) ? '>' : '<';

	while(ask(piv) == comp) {
		if(piv < 0 || piv >= n) return;

		exp++;
		piv = x+(1<<exp)*dir;

	}
	int l = min(piv-(1<<exp)*dir, piv);
	int r = max(piv-(1<<exp)*dir, piv);


	while(l+1 < r) {
		int mid = (l+r)/2;
		if(ask(mid) == '>') {
			l = mid;
		}
		else {
			r = mid;
		}
	}

	int xp = x + 2*(l-x);
	if(dir == -1) xp += 2;

	linear_exploration(xp-LEL, xp+LEL, dir);
}

void register_pos(int x, int dir) {

	cerr << "register_pos(" << x << ", " << dir << ")" << endl;

	if(ask(x) == '<' && ask(x+1) == '>') {
		if(pos.find(x) == pos.end()) {
			pos.insert(x);
			if(dir <= 0) explore(x, -1);
			if(dir >= 0) explore(x+1, 1);
		}
	}
}




int main() {
	cin >> n >> m;

	int l = 0;
	int r = n;
	while(r > l+1) {
		int mid = (l+r)/2;
		char c = ask(mid);
		if(c == '<') {
			l = mid;
		}
		else {
			r = mid;
		}
	}

	linear_exploration(l-LEL, l+LEL, 0);

	//assert((int)pos.size() == m);

	int prev_pos = -1;

	vector<int> ans;

	for(auto it=pos.begin(); it != pos.end(); ++it) {
		int x = *it;
		if(prev_pos == -1 || (x-prev_pos)%2 == 0) {
			x++;
		}
		ans.push_back(x);
		prev_pos = x;
	}

	cout << "! ";
	for(int i=0; i < m; ++i) {
		cout << ans[i];
		if(i != m-1) cout << " ";
	}
	cout << endl;



}