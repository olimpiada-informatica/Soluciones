#include<bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	while (cin >> a >> b >> c) {
		if (b > a) swap(a,b);
		if (c > a) swap(a,c);
		if (a < b + c) cout << "si" << endl;
		else cout << "no" << endl;
	}
}
