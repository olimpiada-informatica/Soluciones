#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		string a;
		cin >> n >> k >> a;
		queue<int> A[26];
		for (int i = 0; i < n; ++i) 
			A[a[i]-'a'].push(i);
		int it = 0;
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < 26; ++j) {
				while (!A[j].empty() and A[j].front() < it) A[j].pop();
				if (A[j].empty()) continue;
				int d = A[j].front();
				if (n - d >= k - i) {
					it = d;
					A[j].pop();
					cout << char('a' + j);
					break;
				}
			}
		}
		cout << endl;
	}
}
