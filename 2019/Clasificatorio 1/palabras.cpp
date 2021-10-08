#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		string s,t;
		cin >> s >> t;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '?') s[i] = 'a';
			if (t[i] == '?') t[i] = 'z';
		}
		if (s < t) cout << "si" << endl;
		else cout << "no" << endl;
	}
}
