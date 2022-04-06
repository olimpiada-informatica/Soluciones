#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	unordered_set<int> mod_set;

	int count_0 = 0;
	int count_1_2 = 0;
	int count_gen = 1;

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
			mod_set.insert(m-mod);
		}
	}	
	int res = max({count_0, count_1_2, count_gen});
	if (2*res > n) cout << -1 << '\n';
	else cout << res << '\n';
}
