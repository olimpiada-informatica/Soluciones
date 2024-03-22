#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> positive;
        vector<int> negative;
        for (int i=0; i < n; ++i) {
            int x;
            cin >> x;
            if (i%2 == 0) {
                positive.push_back(x);
            }
            else {
                negative.push_back(x);
            }
        }

        long long ans = 0;
        if (n == 2) {
            if (k%2) swap(positive[0], negative[0]);
            ans = positive[0]-negative[0];
        }
        else {
            int a = 0;
            int b = (int)negative.size()-1;
            sort(positive.begin(), positive.end());
            sort(negative.begin(), negative.end());
            while (k > 0 && b >= 0) {
                if (positive[a] > negative[b]) break;
                swap(positive[a], negative[b]);
                a++;
                b--;
                k--;
            }
            for (int x : positive) ans += x;
            for (int x : negative) ans -= x;

        }
        cout << ans << endl;
    }
}
