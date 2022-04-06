#include<bits/stdc++.h>

using namespace std;

bool solve() {
	int n;
	cin >> n;
	int f_const;
	int c_min=2e9, c_max = -2e9;
	bool mal = false;
	for(int i = 0; i < n; ++i) {
		int f,c;
		cin >> f >> c;
		if(i == 0) f_const = f;
		else if(f_const != f) mal = true;
		if(c%2 == 0) c /= 2, c--;
		else c = - (c+1)/2;
		c_min = min(c_min, c);
		c_max = max(c_max, c);
	}
	if(mal) return false;
	return c_max-c_min+1 == n;
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