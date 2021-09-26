#include <iostream>
#include <vector>

using namespace std;
typedef vector <int> vi;

int solve(string& s){
    int n = s.size();

    vi dp(n, 0);
    int ans = 0;

    for (int i = 1; i < n; ++i){
        for (int j = 0; j < i; ++j){
            if (s[i] > s[j]) dp[i] += (dp[j] + 1);
        }

        ans += dp[i];
    }

    return ans;
}


int main(){
    string s;
    while (cin >> s) cout << solve(s) << endl;
}