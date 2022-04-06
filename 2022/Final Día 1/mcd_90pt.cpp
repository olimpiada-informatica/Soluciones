//Esta solucion obtiene aproximadamente 90 puntos - se puede hacer mejor. 

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ask(ll a, ll b) {
	cout << "? " << a << " " << b << endl;
	ll res;
	cin >> res;
	if(res == 0 || res == -1) exit(0);
	return res;
}

int main() {
	
	ll i = 0;
	ll x = 0;
	ll y = 0;
	while(true) {
		if((ask(x, y)&((1LL<<(i+1))-1)) == 0) {

		}
		else if((ask(x+(1LL<<i), y)&((1LL<<(i+1))-1))  == 0) {
			x += (1LL << i);
		}
		else if((ask(x, y+(1LL<<i))&((1LL<<(i+1))-1)) == 0) {
			y += (1LL<<i);
		}
		else {
			x += (1LL<<i);
			y += (1LL<<i);
		}
		i++;
	}
}