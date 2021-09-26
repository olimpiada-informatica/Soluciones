#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;


int main(){
    int t, n;
    
    while (cin >> t >> n){
        vi V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];

        sort(V.begin(), V.end());

        int total = 0;
        for (int i = 0; i < n; ++i){
            if (V[i] <= t){
                ++total;
                t -= V[i];
                --t;
            }
            else i = n+2;
        }

        cout << total << endl;
    }
}