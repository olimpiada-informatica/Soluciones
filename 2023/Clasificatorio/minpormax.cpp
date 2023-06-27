#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<ll>;

const ll mod = 1e9+7;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n); 
        for(ll& x : a) cin >> x;

        vi min_end(n);
        vi min_st;
        ll min_sum = 0;

        min_st.push_back(0);
        min_sum = a[0];
        min_end[0] = a[0];

        for (int i=1; i < n; ++i) {
            while(!min_st.empty() && a[i] < a[min_st.back()]) {
                int j = min_st.back();
                min_st.pop_back();
                int nxt = -1;
                if(!min_st.empty()) nxt = min_st.back();
                min_sum -= a[j]*(j-nxt);
            }
            int j = -1;
            if (!min_st.empty()) j = min_st.back();
            min_sum += a[i]*(i-j);
            min_st.push_back(i);
            min_end[i] = min_sum%mod;
        }

        vi max_sta(n);
        vi max_st;
        ll max_sum = 0;

        max_st.push_back(n-1);
        max_sum = a[n-1];
        max_sta[n-1] = a[n-1];

        for (int i=n-2; i > -1; --i) {
            while(!max_st.empty() && a[i] > a[max_st.back()]) {
                int j = max_st.back();
                max_st.pop_back();
                int nxt = n;
                if(!max_st.empty()) nxt = max_st.back();
                max_sum -= a[j]*(nxt-j);
            }
            int j = n;
            if (!max_st.empty()) j = max_st.back();
            max_sum += a[i]*(j-i);
            max_st.push_back(i);
            max_sta[i] = max_sum%mod;
        }

        vi smax(n);
        smax[n-1] = max_sta[n-1];
        for (int i=n-2; i > -1; --i) {
            smax[i] = (smax[i+1] + max_sta[i])%mod;
        }

        ll ans = 0;

        for (int i=0; i+1 < n; ++i) {
            ans += min_end[i]*smax[i+1];
            ans %= mod;
        }

        cout << ans << endl;
    
    }
}