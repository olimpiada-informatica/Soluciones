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
 
#define piiii pair<pii,pii>
 
char play(int d){
    cout << d << endl;
    char c;
    cin >> c;
    return c;
}
 
bool solve(){
    int n,k;
    cin >> n >> k;
 
    int pot = 1;
    while (2*pot<n) pot*=2;
 
    if (2*pot==n){
        play(pot);
        play(pot);
        return 1;
    }
    else{
        char dir = play(pot);
        play(n-pot);
        int ac = 2*pot-n;
        for (int i=0;;i++) if ((1LL<<i) & ac){
            char c = play((1LL << i));
            if (c=='=') return 1;
            if (c=='-') return 0;
            if (c==dir) ac+=(1LL<<i);
            else ac-=(1LL<<i);
        }
    }
}
 
signed main(){
    int t;
    cin >> t;
    while (t-- && solve()){};
}
