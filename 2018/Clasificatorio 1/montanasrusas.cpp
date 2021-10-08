#include <bits/stdc++.h>

using namespace std;

const long long MOD=1e9+7;

vector <vector <vector <long long> > >dp;
int l, h;

long long calc(int a, int b, int c) {
	if(b<0 or b>h) return 0;
	if(dp[a][b][c]!=-1) return dp[a][b][c];
	if(b==c) return dp[a][b][c]=(calc(a-1, b-1, c)+calc(a-1, b-1, c-1))%MOD;
	return dp[a][b][c]=(calc(a-1, b-1, c)+calc(a-1, b+1, c))%MOD;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	dp=vector <vector <vector <long long> > >(405, vector <vector <long long> >(205, vector <long long>(205, -1)));
	for(int i=0;i<=203;++i){
		for(int j=0;j<=203;++j){
			dp[0][i][j]=0;
		}
	}
	dp[0][0][0]=1;
	int t;
	cin >> t;
	while (t--) {
		cin >> l >> h;
		cout << calc(2*l, 0, h) << endl;
	}
}
