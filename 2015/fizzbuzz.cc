#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		bool done = false;
		if (i%3 == 0){
			cout << "Fizz";
			done = true;
		}
		if (i%5 == 0){
			cout << "Buzz";
			done = true;
		}
		if (!done)
			cout << i;
		cout << '\n';
	}
}