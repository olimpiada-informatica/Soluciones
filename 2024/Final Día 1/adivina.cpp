#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

vvll dp;

const int STREAK_LIMIT = 7;

ll f(int q, int r) {
    if (dp[q][r] != -1) return dp[q][r];
    if (q == 0) {
        return dp[q][r] = 0;
    }
    if (q == 1) {
        return dp[q][r] = 1;
    }
    if (r+1 == STREAK_LIMIT) {
        return dp[q][r] = f(q-1, 1)+1;
    }
    return dp[q][r] = f(q-1, r+1) + f(q-1, 1) + 1;
}

bool ask(ll y) {
    cout << "? " << y << endl;
    char c;
    cin >> c;
    if (c == '=' || c == '-') exit(0);
    return c == '<';
}

ll N;

int main() {
    int Q;
    
    cin >> N >> Q;

    dp = vvll(Q+1, vll(STREAK_LIMIT, -1));

    ll L = 1;
    ll R = N;

    int prev_ans = -1; // 1 if <, 0 if >
    int streak = 0;

    while(Q--) {
        ll y;
        if (streak+1 == STREAK_LIMIT) {
            if (prev_ans) y = L;
            else y = R;
        }
        else {
            if (prev_ans) y = min(L + f(Q, streak+1), R);
            else y = max(R - f(Q, streak+1), L);
        }
        
        int ans = ask(y);
        if (ans == prev_ans) streak++;
        else {
            prev_ans = ans;
            streak = 1;
        }
        if (ans) R = y-1;
        else L = y+1;
    }


    
}
