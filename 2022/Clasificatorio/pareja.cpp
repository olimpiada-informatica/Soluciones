#include<bits/stdc++.h>

using namespace std;



bool ask(const vector<bool>& v) {
	cout << "? ";
	for(int i=0; i < (int)v.size(); ++i) {
		cout << (v[i] ? "1" : "2") << " ";
	}
	cout << endl;
	char c;
	cin >> c;
	if(c == 'e') exit(0);
	return c == 'd';
}



int main() {
	int n;
	cin >> n;

	int len = 1;
	while(len < n) len *= 2;
	vector<bool> v(n);
	while(true) {
		for(int i=0; i < n; ++i) {
			v[i] = (i%len) < len/2;
		}
		if(ask(v)) break;
		len /= 2;
	}
	int m = n/len;
	if(n%len) m++;

	int l = 0; 
	int r = m;
	while(r-l > 1) {
		int mid =(l+r)/2;
		for(int i=0; i < n; ++i) {
			v[i] = (i%(len)) < len/2;
		}
		for(int i=0; i < mid*len; ++i) {
			v[i] = true;
		}
		if(ask(v)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	int block = l;
	l = len*block;
	r = len*block+len/2;
	while(r-l > 1) {
		int mid = (l+r)/2;
		for(int i=0; i < n; ++i) {
			v[i] = (i < mid);
		}
		if(ask(v)) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	int a = l;
	l = len*block+len/2;
	r = len*block+len;
	while(r-l > 1) {
		int mid = (l+r)/2;
		for(int i=0; i < n; ++i) {
			v[i] = (i < mid);
		}
		if(ask(v)) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	int b = l;
	cout << "! " << a+1 << " " << b+1 << endl;



	
}