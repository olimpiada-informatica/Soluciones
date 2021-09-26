#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <string>
#include <sstream>
 
using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;

int prefix(string& a, string& b){
    int ans = 0;
    while (ans < a.size() and ans < b.size() and a[ans] == b[ans]) ++ans;
    return ans;
}

bool comp(const vector <string>& A, vector <string>& B){
    if (A[0].size() != B[0].size()) return A[0].size() < B[0].size();
    return A[1] < B[1];
}

int main (){
    bool first = true;

    int n;
    while (cin >> n){
        if (first) first = false;
        else cout << "----------" << '\n';

        vector <string> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];

        sort(V.begin(), V.end());

        vector <vector <string> > T(n, vector <string> (2));

        for (int i = 0; i < n; ++i){

            int value = 0;
            if (i > 0) value = max(value, prefix(V[i], V[i-1]));
            if (i < n-1) value = max(value, prefix(V[i], V[i+1]));
            
            T[i] = {V[i].substr(0, value + 1), V[i]};
        }

        sort(T.begin(), T.end(), comp);
        for (auto x: T)  cout << x[0] << " " << x[1] << '\n';
    }    
}   