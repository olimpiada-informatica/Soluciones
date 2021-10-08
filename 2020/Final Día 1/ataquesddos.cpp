#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<ll,ll>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vs = vector<string>;
 
#define order(a) sort(a.begin(),a.end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
const ll inf = 2000000000000000000LL;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> q;
        q--;
        ll a,b,d;
        int mode;
        map<string,int> dic;
        vvii acum;
        cin >> mode >> a >> b >> d;
        int it = 0;
        while(q--){
            cin >> mode;
            if(mode == 2){
                cin >> a >> b >> d;
                continue;
            }
            string ip;
            ll temp, tam;
            cin >> ip >> temp >> tam;
            if(dic.count(ip) == 0){
                dic[ip] = it++;
                acum.push_back(vii(1,ii(-1,0)));
            }
            vii& base = acum[dic[ip]];
            auto pos = lower_bound(base.begin(), base.end(),ii(temp-d+1,-2));
            if(pos != base.begin()) pos--;
            if(base.end() - pos-1 >= a or base.back().second - pos->second >= b) cout << "ig" << endl;
            else{cout << "ac" << endl;
            base.push_back(ii(temp,base.back().second+tam));
        }
        }
        cout << "--" << endl;
    }
}
