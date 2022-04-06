#include<bits/stdc++.h>

using namespace std;

bool solve() {
	int n;
	cin >> n;
	map<char, pair<char,char>> mp;
	for(int i = 0; i < n; ++i) {
		char a,b,c,d;
		cin >> a >> d >> d >> b >> c;
		mp[a] = pair<char,char>(b,c);
	}
	string s, t;
	cin >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	while(s.size() != 0 and t.size() != 0) {
		if(s.size() > t.size()) return false;
		char last = s.back();
		if(last == t.back()) {
			s.pop_back();
			t.pop_back();
			continue;
		}
		if(mp.count(last) == 0) return false;
		s.pop_back();
		s.push_back(mp[last].second);
		s.push_back(mp[last].first);
	}
	return s.size() == 0 and t.size() == 0;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		if(solve())
			cout << "SI" << endl;
		else
			cout << "NO" << endl;
	}
}