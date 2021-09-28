#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void dump (vi seq, vi& sta, vi& dir, vi& mir, int& last_pos, int& last_i) {
	int n = seq.size();

	cerr << "SEQ: " << endl;
	for(int i=0; i < n; ++i) cerr << seq[i] << " ";
	cerr << endl << endl;
	
	cerr << "STA: " << endl;
	for(int i=0; i < n; ++i) cerr << sta[i] << " ";
	cerr << endl << endl;

	cerr << "DIR: " << endl;
	for(int i=0; i < n; ++i) cerr << dir[i] << " ";
	cerr << endl << endl;

	cerr << "MIR: " << endl;
	for(int i=0; i < n; ++i) cerr << mir[i] << " ";
	cerr << endl << endl;

	cerr << "LP: " << last_pos << " LI: " << last_i << endl << endl;
}

void solve (vi seq, bool ord, vi& sta, vi& dir, vi& mir, int& last_pos, int& last_i) {
	int n = seq.size();
	last_pos = 1;
	last_i = 0;
	int cur_pos = 1;
	int cur_typ = seq[0];
	sta[0] = seq[0];
	dir[0] = 1;

	for(int i=1; i < n; ++i) {
		int typ = seq[i];
		if(typ == cur_typ) {
			dir[i] = 1;
		}
		else dir[i] = -1;
		cur_pos += dir[i];
		if(dir[i] == -1 and (cur_pos < 0 or sta[cur_pos] != cur_typ)) {
			mir[last_i+1] = !mir[last_i+1];
			int new_pos = last_pos + (last_pos-cur_pos);
			for(int j=last_pos; j < new_pos; ++j) {
				if(cur_pos < 0) sta[j] = !sta[0];
				else sta[j] = sta[cur_pos];
			}
			cur_pos = new_pos;
			last_pos = new_pos;
			last_i = i;
			cur_typ = !cur_typ;
			if(i+1 < n) mir[i+1] = !mir[i+1];
		}
		else if(dir[i] == 1 and cur_pos > last_pos) {
			last_i = i;
			sta[cur_pos-1] = sta[cur_pos-2];
			last_pos = cur_pos;
		}
		else if(ord and cur_pos == last_pos) {
			last_i = i;
		}

		//cerr << "i = " << i << " cur_pos = " << cur_pos << endl;
	}
}

int main() {

	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		//n = s.length();

		vi sta1 = vi(n);
		vi dir1 = vi(n);
		vi mir1 = vi(n);

		int lp1, li1;

		vi seq1(n);
		for(int i=0; i < n; ++i) seq1[i] = (s[i] == 'D');

		solve(seq1, false, sta1, dir1, mir1, lp1, li1);

		vi sta2 = vi(n);
		vi dir2 = vi(n);
		vi mir2 = vi(n);

		int lp2, li2;

		vi seq2(n);
		for(int i=0; i < n; ++i) seq2[i] = (s[n-i-1] == 'I');

		solve(seq2, true, sta2, dir2, mir2, lp2, li2);

		if(sta1 == sta2 and lp1 == lp2 and li1+li2 == n-2) {
			cout << "SI" << endl;

			cout << lp1 << endl;
			for(int i=0; i < lp1; ++i) {
				if(sta1[i]) cout << 'D';
				else cout << 'I';
			}
			cout << endl;

			int m1 = 1; 
			int m2 = 1;
			for(int i=0; i < n; ++i) {
				if(mir1[i]) m1 *= -1;
				if(mir2[i]) m2 *= -1;
				dir1[i] *= m1;
				dir2[i] *= m2;
			}

			vi turns;
			int cp = 1;
			for(int i=1; i < li1; ++i) {
				if(dir1[i] != dir1[i-1]) {
					turns.push_back(cp);
				}
				cp += dir1[i];
			}
			turns.push_back(lp2);
			cp = lp2-1;
			for(int i=li2-1; i >= 0; --i) {
				if(dir2[i] != dir2[i+1]) {
					turns.push_back(cp);
				}
				cp -= dir2[i];
			}

			int l = turns.size();
			cout << l << endl;
			for(int i=0; i < l; ++i) {
				cout << turns[i] << " ";
			}
			cout << endl;



		}
		else {
			cout << "NO" << endl;
		}
	}
	/*
	dump(seq1, sta1, dir1, mir1, lp1, li1);
	dump(seq2, sta2, dir2, mir2, lp2, li2);
	*/


}