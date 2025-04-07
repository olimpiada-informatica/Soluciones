#include<bits/stdc++.h>
    
using namespace std;
    
#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define pii pair<int,int>
#define vii vector<pii>
#define vvii vector<vii>
#define fi first
#define se second
#define pb push_back
 
#define vd vector<double>
#define sz(x) (int)(x).size()
 
#define FOR(i, a, b) for(int i = a; i < (b); ++i)
 
void solve(){
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int &x:v) cin >> x;
    int s=0;
    for (int &x:v) s+=x;
    if ((k-1)*((s+1)/2)<n-1){
        cout << "NO" << endl;
        return;
    }
    else{
        vi zeros;
        priority_queue<pii> nozeros;
        FOR(i,0,n){
            if (v[i]) nozeros.push({-v[i],i+1});
            else zeros.pb(i+1);
        }
        vvi ans;
        while (1){
            assert(sz(nozeros));
            if (sz(zeros)+sz(nozeros)<=k){
                vi lastv;
                while (sz(nozeros)){
                    lastv.pb(nozeros.top().se);
                    nozeros.pop();
                }
                for (int x:zeros) lastv.pb(x);
                ans.pb(lastv);
 
                cout << "SI" << endl;
                cout << sz(ans) << endl;
                for (vi &w:ans){
                    cout << sz(w) << endl;
                    for (int x:w) cout << x << ' ';
                    cout << endl;
                }
                return;
            }
            else if (nozeros.top().fi==-1 || !sz(zeros)){
                assert(sz(nozeros)>=2);
                pii p1=nozeros.top();
                nozeros.pop();
                pii p2=nozeros.top();
                nozeros.pop();
 
                vi vida={p1.se,p2.se};
                while (sz(zeros) && sz(vida)<k){
                    vida.pb(zeros.back());
                    zeros.pop_back();
                }
                ans.pb(vida);
 
                ans.pb({p2.se});
 
                if (p2.fi==-1) zeros.pb(p2.se);
                else nozeros.push({p2.fi+1,p2.se});
            }
            else{
                pii p=nozeros.top();
                nozeros.pop();
 
                vi vida={p.se};
                while (sz(zeros) && sz(vida)<k){
                    vida.pb(zeros.back());
                    zeros.pop_back();
                }
                ans.pb(vida);
                ans.pb({p.se});
 
                if (p.fi==-2) zeros.pb(p.se);
                else nozeros.push({p.fi+2,p.se});
            }
        }
    }
}
 
signed main(){
    int t;
    cin >> t;
    while (t--) solve();
}
