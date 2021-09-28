#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

using ll = long long int;
using ii = pair<ll, ll>;
using vii = vector<ii>;

int main() {
	int n;
	cin >> n;

	vii v(n);
	for (ii& x : v) cin >> x.first;
	for (ii& x : v) cin >> x.second;

	ll sumatotal = 0;
	ll sumaprio_delante = 0, sumaprio_detras = 0;
	for (int j = 1; j < n; ++j) {
		sumatotal += v[j].second * abs(v[0].first - v[j].first);
		sumaprio_detras += v[j].second;
	}

	ll minsuma = sumatotal;
	int midx = 0;

	for (int i = 1; i < n; ++i) {
		sumatotal -= sumaprio_detras * (v[i].first - v[i - 1].first);
		sumaprio_detras -= v[i].second;

		sumaprio_delante += v[i - 1].second;
		sumatotal += sumaprio_delante * (v[i].first - v[i - 1].first);
		
		if (sumatotal < minsuma) {
			minsuma = sumatotal;
			midx = i;
		}
	}

	cout << midx << '\n';

	return 0;
}