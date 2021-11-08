#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k, m;
	while (cin >> n >> k >> m){
		vector<int> v(n);
		for (int& x : v)
			cin >> x;
		vector<int> s(k, 0);
		int l = 0, r = 0;
		int ans = n;
		while (true){
			if (m > 0){
				if (r == n)
					break;
				if (s[v[r++]]++ == 0)
					m--;
			}
			else{
				ans = min(ans, r-l);
				if (s[v[l++]]-- == 1)
					m++;
			}
		}
		cout << ans << '\n';
	}
}