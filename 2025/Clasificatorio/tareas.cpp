#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000001;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> t(n);
        vector<int> p(n);
        for (int i=0; i < n; ++i) cin >> t[i] >> p[i];
        vector<int> dp(n+1, INF);
        dp[0] = 0;
        for (int i=0; i < n; ++i) {
            for (int j=n-1; j > -1; --j) {
                if (dp[j] <= p[i]) {
                    dp[j+1] = min(dp[j+1], dp[j] + t[i]);
                }
            }
        }
        int ans = n;
        while (dp[ans] == INF) ans--;
        cout << ans << endl;
    }
}