#include<bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--) {
		int a, b;
		cin >> a >> b;
		if(a < b) swap(a, b);
		cout << ((a%2 == 0 || b%2 == 0) ? a+b : a-b) << endl;
	}
}