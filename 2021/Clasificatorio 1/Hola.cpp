#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main() {
	int T;
	cin >> T;
	while(T--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		cout << (s == "ahlo" ? "SI" : "NO") << endl;
	}
	
}