#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvvvi> vvvvvi;



int main (){
    int n, l;
    while (cin >> n >> l){
        vector <ll> lon(n), people(n);

        for (int i = 0; i < n; ++i) cin >> lon[i];
        for (int i = 0; i < n; ++i) cin >> people[i];

        vector <ll> L(n+1, 0), P(n+1, 0);
        for (int i = 0; i < n; ++i) L[i+1] = L[i] + lon[i];
        for (int i = 0; i < n; ++i) P[i+1] = P[i] + people[i];

        int start = 1, end = 0, ans = -1, current_start = 1;

        for (int i = 1; i <= n; ++i){
            ll x = L[i] - L[current_start-1];

            if (x <= l){
                int p = P[i] - P[current_start-1];

                if ((p > ans) or (p == ans and x > L[end] - L[start-1])){
                    start = current_start;
                    end = i;
                    ans = p;
                }
            }
            else {
                while (current_start <= i and L[i] - L[current_start-1] > l) ++current_start;
                if (current_start <= i){
                    int p = P[i] - P[current_start-1];
                    x = L[i] - L[current_start-1];

                    if ((p > ans) or (p == ans and x > L[end] - L[start-1])){
                        start = current_start;
                        end = i;
                        ans = p;
                    }
                }
            }
        }

        if (ans == -1) cout << "0 0 0\n";
        else cout << L[start-1] << " " << L[end] << " " << ans << '\n';
    }
}