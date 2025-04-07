#include<bits/stdc++.h>

using namespace std;
    
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back

#define sz(x) (int)(x).size()
    
signed main(){
    int t;
    cin >> t;
    while (t--){
        int n,m,l,r;
        cin >> n >> m >> l >> r;
        vi a(n), b(m);
        for (int &x:a) cin >> x;
        for (int &x:b) cin >> x;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
    
        int ans=0;
        vvi intervals(n-1);
        int ac=0;
        if (b[0]<a[0]) ans+=l*(a[0]-b[0]);
        if (b.back()>a.back()) ans += r*(b.back()-a.back()); 
        for (int x:b){
            while (ac<n && x>=a[ac]) ac++; // ac is first bigger
            if (ac!=0 && ac!=n) intervals[ac-1].pb(x);
        }
        for (int i=0;i<n-1;i++) if (sz(intervals[i])){
            int k = sz(intervals[i]);
            int interans = min(l*(a[i+1]-intervals[i][0]),r*(intervals[i].back()-a[i]));
            for (int j=0;j<k-1;j++) interans = min(interans, r*(intervals[i][j]-a[i])+l*(a[i+1]-intervals[i][j+1]));
            ans+=interans;
        }
    
        cout << ans << '\n';
    }
}