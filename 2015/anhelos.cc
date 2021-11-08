#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while (cin >> n){
		vector<int> v(n);
		int suma = 0;
		for (int& x : v){
			cin >> x;
			suma += x;
		}
		for (int i = 0; i < n-1; i++){
			cout << suma-v[i] << ' ';
		}
		cout << suma-v[n-1] << '\n';
	}
}