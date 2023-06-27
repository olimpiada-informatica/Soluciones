#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
const int mod = 202220233LL;
int n, x;

int powerp(int a, int b, int m){
    if( b == 1) return a % m;
    return  powerp((a*a*1LL) % m, 1LL*b/2, 1LL*m)*(b % 2 == 1 ? a*1LL : 1LL) % m;
}

int inversep(int a, int p){
    return powerp(a, p-2, p);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> C(1003, vector<int> (1003));
    C[0][0] = 1; //C(0, 0)
    for (int i = 1; i <= 1002; i++) {
        C[i][0] = C[i-1][0]; //Computa C(i, 0)
    }
    
    for (int i = 1; i <= 1001; i++) {
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod; //Computa C(i, j)
        }
    }
    
    int T; cin >> T; while (T--) {
		cin >> n >> x;
		x--;
		
		vector<int> sums(n+1);
		for (int i = 0; i <= n; i++) {
			int k = (powerp(x+1, i+1, mod) - 1 + mod) % mod;
			for (int j = i-1; j >= 0; j--) {
				k -= (C[i+1][j]*sums[j]) % mod;
				k = (k + 2*mod) % mod;
			}
			k = (k*inversep(i+1, mod))%mod;
			sums[i] = k;
		}

		
		for (int i = 1; i <= n; i++) {
			if (i != n) cout << (C[n][i] * sums[n-i])%mod << " ";
			else cout << (C[n][i] * sums[n-i]+1)%mod << " "; //case everything equal to 1
		}
		cout << "\n";
	}
}


