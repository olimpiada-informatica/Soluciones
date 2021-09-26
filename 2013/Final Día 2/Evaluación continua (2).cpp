#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;

int main (){
    int n, k;
    while (cin >> n >> k){

        vi V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];

        int sum = 0;
        for (int i = 0; i < k; ++i) sum += V[i];

        vi sums(n, V[0]);
        for (int i = 1; i < n; ++i) sums[i] = max(V[i], sums[i-1] + V[i]);

        int ans = sum;
        for (int i = k; i < n; ++i){
            sum += (V[i] - V[i-k]);

            ans = max(ans, max(sum, sum + sums[i-k]));
        }

        cout << ans << '\n';
    }
}