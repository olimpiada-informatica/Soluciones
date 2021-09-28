#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dict;
vector<int> len;
int N;
vector<char> letras(26, 0);

bool posible(int k) {
	for (int i = 0; i < 26; i++) {
		if (letras[i] < dict[k][i])
			return false;
	}
	return true;
}

int main() {
	cin >> N;
	string S;
	dict.assign(N, vector<int>(26, 0));
	len = vector<int>(N);
	for (int i = 0; i < N; i++) {
		cin >> S;
		for (int j = 0; j < (int) S.length(); j++)
			dict[i][S[j] - 'A']++;
		len[i] = (int) S.length();
	}
	char ficha;
	for (int i = 0; i < 7; i++) {
		cin >> ficha;
		letras[ficha - 'A']++;
	}
	int record = 0;
	for (int i = 0; i < N; i++) {
		if (len[i] > record && posible(i))
			record = len[i];
	}
	if (record <= 3) cout << record;
	else cout << 2*record;
	return 0;
}
