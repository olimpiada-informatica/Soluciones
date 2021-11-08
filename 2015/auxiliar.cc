#include <bits/stdc++.h>

using namespace std;

int main(){
	cout << "20000\n";
	for (int i = 1; i<=200; i++){
		for (int k = 0; k < i; k++)
			cout << 'a';
		cout << '\n';
	}
	for (int i = 201; i <= 20000; i++){
		for (int k = 0; k < 200; k++)
			cout << (char)('a'+rand()%26);
		cout << '\n';
	}
	cout << "20000\n";
	for (int i = 1; i<=200; i++){
		for (int k = 0; k < i; k++)
			cout << 'a';
		cout << '\n';
	}
	for (int i = 201; i <= 20000; i++){
		for (int k = 0; k < 200; k++)
			cout << (char)('a'+rand()%26);
		cout << '\n';
	}
	for (int i = 0; i < 20000; i++)
		cout << 'a';
	cout << '\n';
}