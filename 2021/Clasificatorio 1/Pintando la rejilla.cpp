#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int solve() {

	//cerr << "START CASE" << endl;


	int n, m;
	cin >> n >> m;
	vi a(n);
	vi b(m);
	for(int i=0; i < n; ++i) cin >> a[i];
	for(int j=0; j < m; ++j) cin >> b[j];

	int ans = 0;
	vi a_st;
	vi b_st;
	vi a_null(n, 0);
	vi b_null(m, 0);

	for(int i=n-1; i > -1; --i) {
		while(!a_st.empty() && a[a_st.back()] <= a[i]) {
			a_st.pop_back();
		}
		a_st.push_back(i);
	}

	for(int j=m-1; j > -1; --j) {
		while(!b_st.empty() && b[b_st.back()] <= b[j]) {
			b_st.pop_back();
		}
		b_st.push_back(j);
	}


	for(int i=0; i < (int)a_st.size(); ++i) {
		//cerr << a_st[i] << " ";
	}
	//cerr << endl;
	for(int i=0; i < (int)b_st.size(); ++i) {
		//cerr << b_st[i] << " ";
	}
	//cerr << endl;


	int ci = (int)a_st.size()-1;
	int cj = (int)b_st.size()-1;

	for(int i=0; i < n; ++i) {

		while(cj > -1 && i+1 > b[b_st[cj]]) {
			cj--;
		}


		//cerr << "i " << i << " cj " << cj << " b_st[cj] " << (cj > -1 ? b_st[cj] : -1) << " b[b_st[cj]] " << (cj > -1 ? b[b_st[cj]] : -1) << endl;



		if(cj == -1 || a[i] < b_st[cj]+1) {



			//cerr << "HORIZONTAL NULL i =  " << i << endl;



			a_null[i] = 1;
			ans++;
		}
	}

	for(int j=0; j < m; ++j) {
		while(ci > -1 && j+1 > a[a_st[ci]]) {
			ci--;
		}
		if(ci == -1 || b[j] < a_st[ci]+1) {


			//cerr << "VERTICAL NULL j =  " << j << endl;


			b_null[j] = 1;
			ans++;
		}
	}

	ci = 0;
	cj = 0;

	while(ci < (int)a_st.size() && cj < (int)b_st.size()) {

		//cerr << "BEGIN ITERATION " << ci << " " << cj << endl;

		while(ci < (int)a_st.size() && a_null[a_st[ci]]) ci++;
		while(cj < (int)b_st.size() && b_null[b_st[cj]]) cj++;

		bool cont = true;
		
		while(ci < (int)a_st.size() && cj < (int)b_st.size() && cont) {

			//cerr << a_st[ci] << " " << a[a_st[ci]] << " " << b_st[cj] << " " << b[b_st[cj]] << endl;

			int prevci = ci;
			while(cj < (int)b_st.size() && (b[b_st[cj]] >= a_st[ci]+1)) {
			 	cj++;
			}
			cj--;
			while(ci < (int)a_st.size() && (a[a_st[ci]] >= b_st[cj]+1)) {
			 	ci++;
			}
			ci--;
			cont = prevci < ci;

			//cerr << "prevci " << prevci << " ci " << ci << endl;
		}

		ci++;
		cj++;
		ans++;

		//cerr << "END ITERATION " << ci << " " << cj << endl;
	}



	return ans;


}

int main() {
	int T;
	cin >> T;
	while(T--) {
		cout << solve() << endl;
	}
}