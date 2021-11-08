#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9+7;

int main(){
	int n;
	while (cin >> n){
		vector<int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
			if (v[i] == 0){
				v.pop_back();
				n--;
				i--;
			}
		}
		if (n == 0){
			cout << "0\n";
			continue;
		}
		ll ans = 1;
		int idx = n-1;
		while (idx >= 0){
			if (v[idx] >= 3){
				if (idx == 0 or v[idx-1] > 1 or (idx > 1 and v[idx-2] < v[idx])){
					ans = ans*v[idx]%MOD;
					v.pop_back();
					idx--;
				}
				else{
					ans = ans*(v[idx]+1)%MOD;
					v.pop_back();
					v.pop_back();
					idx -= 2;
				}
			}
			else if (v[idx] == 2){
				if (idx == 0 or v[idx-1] > 1){
					ans = ans*v[idx]%MOD;
					v.pop_back();
					idx--;
				}
				else{
					v.pop_back();
					idx--;
					v[idx] = 3;
				}
			}
			else{
				v.pop_back();
				idx--;
				if (idx >= 0){
					v[idx]++;
				}
			}
		}
		cout << ans << '\n';
	}
}