#include <bits/stdc++.h>

using namespace std;

#define D(v) for(auto i : v) cerr << i << ' '; cerr << endl;
#define Dpair(v) for(auto i : v) cerr << "(" << i.first << ", " << i.second << ") "; cerr << endl;
#define Dmap(m) for(auto i : m) cerr << i.first.first << " " << i.first.second << ": " << i.second << ", "; cerr << endl;
#define x first
#define y second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<pdd, double> pddd;
typedef pair<int, pii> piii;
typedef pair<char, int> pci;

const int INF = 1e9+1;
const int MOD = 1000000007;

void solve(){
    int n;
    cin >> n;
    vector<int> v(n+1);
    v[0] = 0;
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        v[i] = v[i-1] + (c == 'D' ? 1 : -1);
    }
    //cerr << "Case:" << endl;
    //D(v)
    if (v[n] != 0)
        cout << "NO\n";
    else{
        vector<int> pas(1, 0);
        int l = 0, r = 0;
        for (int x : v){
            if (x < l){
                if (pas.back() == l){
                    pas.push_back(x);
                }
                else{
                    for (int i = r-1; i >= x; i--){
                        pas.push_back(i);
                    }
                }
                l = x;
            }
            if (x > r){
                if (pas.back() == r){
                    pas.push_back(r = x);
                }
                else{
                    for (int i = l+1; i <= x; i++)
                        pas.push_back(i);
                }
                r = x;
            }
        }
        //D(pas)
        
        vector<bool> last(n+1, false);
        l = r = 0;
        for (int i = n; i >= 0; i--){
            if (v[i] > r) last[i] = true, r = v[i];
            else if (v[i] < l) last[i] = true, l = v[i];
        }
        //D(last)

        bool possible = true;
        int posPas = 0;
        int posv = 0;
        vector<int> ans;
        bool goingRight = true;
        while (posv < n){
            bool left = posPas > 0 and pas[posPas-1] == v[posv+1];
            bool right = posPas < pas.size()-1 and pas[posPas+1] == v[posv+1];
            if (left and right){
                if (last[posv])
                    right = false;
                else
                    left = false;
            }
            if (not left and not right){
                possible = false;
                break;
            }
            if (left){
                if (goingRight){
                    ans.push_back(posPas);
                    goingRight = false;
                }
                posPas--;
            }
            if (right){
                if (not goingRight){
                    ans.push_back(posPas);
                    goingRight = true;
                }
                posPas++;
            }
            posv++;
        }
        //cerr << (possible ? "posible" : "imposible") << endl;
        //D(ans)
        if (not possible or posPas != 0){
            cout << "NO\n";
        }
        else{
            cout << "SI\n";
            cout << pas.size()-1 << '\n';
            for (int i = 0; i < pas.size()-1; i++){
                cout << (pas[i] < pas[i+1] ? 'D' : 'I');
            }
            cout << '\n';
            cout << ans.size() << '\n';
            for (int x : ans){
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}