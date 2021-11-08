#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;

int main() {
    int n, m;
    while (cin >> n >> m){
    	vector<int> init(n);
    	vector<int> temp(n);
    	for (int i = 0; i < n; i++)
    		cin >> init[i] >> temp[i];
    	vector<pii> intervals(m);
    	for (int i = 0; i < m; i++){
    		string a, b;
    		cin >> a >> b;
    		intervals[i].first = (a[0]-'0')*600 + (a[1]-'0')*60 + (a[3]-'0')*10 + (a[4]-'0');
    		intervals[i].second = (b[0]-'0')*600 + (b[1]-'0')*60 + (b[3]-'0')*10 + (b[4]-'0');
    	}
    	vector<vector<int>> dp(m, vector<int>(n));
    	vector<int> best(m, INF);
    	for (int i = 0; i < n; i++){
    		dp[0][i] = init[i] + (intervals[0].second-intervals[0].first)*temp[i];
    		best[0] = min(dp[0][i], best[0]);
    	}
    	for (int i = 1; i < m; i++){
    		for (int j = 0; j < n; j++){
    			dp[i][j] =  min(dp[i-1][j] + (intervals[i].second - intervals[i-1].second)*temp[j], best[i-1]+init[j]+(intervals[i].second- intervals[i].first)*temp[j]);
    			best[i] = min(best[i], dp[i][j]);
    		}
    	}

    	cout << best[m-1] << '\n';
    }
}