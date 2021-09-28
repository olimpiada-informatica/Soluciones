#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;


const ll N = 4e4;
const ll max_val = 1e9;
const ll pr = 99196813;

vi isprime;
vi primes;

void sieve() {
	isprime = vi(N+50, 1);
	primes = vi();
	isprime[1] = false;
	for(int i=2; i <= N; ++i) {
		if(isprime[i]) {
			primes.push_back(i);
			for(int j=2*i; j <= N; j += i) {
				isprime[j] = false;
			}
		}
	}
}



int main() {
	
	sieve();

	vii pts;

	for(int i=0; i < (int)primes.size(); ++i) {
		ll p = primes[i];
		ll cp = p;
		for(int j=1; j < p; ++j) {
			if(cp > max_val or j*p > N) break;
			pts.emplace_back(j*p, cp);
			cp *= p;
			ll x = j;
			while(x%p == 0) {
				cp *= p;
				x /= p;
			}
		}
	}

	pts.emplace_back(1, 1);
	pts.emplace_back(40001, pr);
	int n = pts.size();
	sort(pts.begin(), pts.end());

	vii rpts;
	rpts.emplace_back(1, 1);

	for(int i=1; i < n-1; ++i) {
		int prev = rpts.back().first;
		int cur = pts[i].first;
		if(cur-prev >= 40 && prev != pts[i-1].first) {
			rpts.push_back(pts[i-1]);
			rpts.push_back(pts[i]);
		} 
		else if(cur-prev >= 30) {
			rpts.push_back(pts[i]);
		}
	}
	rpts.emplace_back(40001, pr);
	pts = rpts;
	n = pts.size();

	int l = 0;
	int r = n;

	int ki = 0;
	for(int i=0; i < n; ++i) {
		if(pts[i].first == 31397) ki = i;
	}

	cout << "? " << pts[ki].second << " " << pts[ki].second << endl;
	string ski;
	cin >> ski;
	if(ski == "SI") {
		l = ki;
		cout << "? " << pts[ki+1].second << " " << pts[ki+1].second << endl;
		cin >> ski;
		if(ski == "NO") {
			r = ki+1;
		}
		else {
			l = ki+1;
		}

	}
	else {
		r = ki;
	}


	
	while(r-l > 1) {
		int mid = (l+r)/2;
		cout << "? " << pts[mid].second << " " << pts[mid].second << endl;
		string s;
		cin >> s;
		if(s == "SI") {
			l = mid;
		}
		else if(s == "NO") {
			r = mid;
		}

	}


	ll cf = 1;
	ll cfv = 1;
	for(int i=pts[l].first; i <= pts[l+1].first; ++i) {
		while(cf <= i) {
			cfv *= cf;
			cfv %= pr;
			cf++;
		}
		cout << "? " << pr-cfv << " " << pr << endl;
		string s;
		cin >> s;
		if(s == "SI") {
			cout << "! " << i << endl;
			break;
		}
		

	}

	

	
}