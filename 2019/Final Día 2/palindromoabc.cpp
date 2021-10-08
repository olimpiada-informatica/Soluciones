#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if ((a%2) + (b%2) + (c%2) > 1) {
			cout << "ROP" << endl;
			continue;
		}
		cout << string(a/2,'A');
		cout << string(b/2,'B');
		cout << string(c/2,'C');
		if (a%2) cout << 'A';
		else if (b%2) cout << 'B';
		else if (c%2) cout << 'C';
		cout << string(c/2,'C');
		cout << string(b/2,'B');
		cout << string(a/2,'A');
		cout << endl;
	}
}
