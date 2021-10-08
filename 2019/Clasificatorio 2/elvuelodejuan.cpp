#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<int> VI;
typedef vector<VI> VVI;


int main(){
	int cas;
	cin >> cas;
	while (cas--) {
		int n;
		cin >> n;
		int ind = 0;
		int val = 1e9;
		for (int i = 1; i <= n; ++i) {
			int res = 0;
			for (int j = 0; j < 3; ++j) {
				int x;
				cin >> x;
				res += x;
			}
			if (res < val) {
				val = res;
				ind = i;
			}
		}
		cout << ind << endl;
	}
}
