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
    
#define sz(x) (int)(x).size()
    
#define piiii pair<pii,pii>
    
signed main(){
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin >> n >> k;
        vi v(n);
        for (int &x:v) cin >> x;
        for (int &x:v) x--;
    
        vii seginfo(n); //iniciseg, finalseg
        int l=0;
        while (l<n){
            int r=l;
            while (r<n-1 && v[r+1]==v[l]) r++;
            for (int i=l;i<=r;i++) seginfo[i]={l,r};
            l=r+1;
        }
    
        vi ans(k,0);
    
        /// INTERSECTING
    
        piiii col1, col2; //firstpos, lastpos, col, number
                        // dos ultimos colores
        col1=piiii{{0,-1},{-1,-1e9}};
        col2=piiii{seginfo[0],{v[0],seginfo[0].se-seginfo[0].fi+1}};
        int ac=seginfo[0].se+1;
        while (ac<n){
            if (v[ac]==col1.se.fi){
                col1.fi.se=seginfo[ac].se;
                col1.se.se+=seginfo[ac].se-seginfo[ac].fi+1;
                swap(col1,col2);
            }
            else if (v[ac]==col2.se.fi){
                col2.fi.se=seginfo[ac].se;
                col2.se.se+=seginfo[ac].se-seginfo[ac].fi+1;
            }
            else{
                if (col1.se.fi!=-1) ans[col1.se.fi] = max(ans[col1.se.fi],col2.se.se);
                ans[col2.se.fi] = max(ans[col2.se.fi],col1.se.se);
    
                col2.fi.fi = col1.fi.se+1;
                col2.se.se = col2.fi.se-col2.fi.fi+1;
    
                col1=col2;
                col2={seginfo[ac],{v[ac],seginfo[ac].se-seginfo[ac].fi+1}};
            }
            ac=seginfo[ac].se+1;
        }
        ans[col1.se.fi] = max(ans[col1.se.fi],col2.se.se);
        ans[col2.se.fi] = max(ans[col2.se.fi],col1.se.se);
    
        //// NON-INTERSECTING
    
        vi longestseg(k);
        for (int i=0;i<n;i++) longestseg[v[i]]=max(longestseg[v[i]],seginfo[i].se-seginfo[i].fi+1);
    
        int xd=0;
        for (int i=0;i<k;i++){
            ans[i]=max(ans[i],xd);
            xd=max(xd,longestseg[i]);
        }
    
        xd=0;
        for (int i=k-1;i>=0;i--){
            ans[i]=max(ans[i],xd);
            xd=max(xd,longestseg[i]);
        }
    
        ///// PRINT
    
        for (int i=0;i<k;i++) cout << ans[i] << ' ';
        cout << endl;
    }
}