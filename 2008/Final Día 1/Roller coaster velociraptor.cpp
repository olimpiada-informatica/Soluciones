#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
 
using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;

int main (){
    int t;
    cin >> t;

    for (int w = 0; w < t; ++w){
        ll N, X, K;
        cin >> N >> X >> K;

        vvi V(N+1, vi(2));
        for (int i = 0; i <= N; ++i) cin >> V[i][0] >> V[i][1];

        ll maximum = 0;
        for (int i = 0; i <= N and V[i][0] <= X; ++i) maximum = max(maximum, V[i][1]);

        cout << maximum * K << endl;
    }
}   