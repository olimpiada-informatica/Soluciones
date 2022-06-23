#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	unordered_map<int, int> mod_set;

	int count_0 = 0;
	int count_1_2 = 0;
	int count_gen = 1;
	
	bool nm1eq = false;

	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		int mod = k%m;
		
		if (mod == 0) {
			++count_0;
		}
		else if (2*mod == m) {
			++count_1_2;
		}
		else {
			if (mod_set.count(mod)) count_gen = 2;
			mod_set[m-mod]++;
			if(mod_set[m-mod] == n-1) {
				nm1eq = true;
			}
		}
	}	
	int res = max({count_0, count_1_2, count_gen});
	if (count_gen == 1 && count_0 <= 1 && count_1_2 <= 1) cout << 1 << '\n';
	else if (n < 4 || nm1eq) cout << -1 << '\n';
	else if (2*res > n) cout << -1 << '\n';
	else cout << res << '\n';
}
