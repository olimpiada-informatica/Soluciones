#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
#include <time.h> 

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

vvvi visited;
vvi visited1;

int T, A, B;
vi possible;

void rec(int t, int w, int a, int b){
    if (visited[w][a][b]) return;    
    visited[w][a][b] = 1;
    if (t > 0) possible[t] = 1;

    rec(t, w - min(w, A - a), a + min(w, A - a), b);
    rec(t, w - min(w, B - b), a, b + min(w, B - b));
    rec(t + min(w, T - t), w - min(w, T - t), a, b);

    rec(0, w + t, a, b);
    rec(t, w + a, 0, b);
    rec(t, w + b, a, 0);

    rec(t - min(t, A - a), w, a + min(t, A - a), b);
    rec(t - min(t, B - b), w, a, b + min(t, B - b));
    
    rec(t + min(T - t, a), w, a - min(a, T - t), b);
    rec(t + min(T - t, b), w, a, b - min(b, T - t));
    
    rec(t, w, a - min(a, B - b), b + min(B - b, a));
    rec(t, w, a + min(A - a, b), b - min(b, A - a));
}

void rec1(int t, int w, int a){
    if (t < 0 or w < 0 or a < 0) return;
    if (t > T or a > A) return;

    if (visited1[w][a]) return;    
    visited1[w][a] = 1;
    if (t > 0) possible[t] = 1;

    rec1(0, w + t, a);
    rec1(t, w + a, 0);

    rec1(t - min(t, A - a), w, a + min(t, A - a));
    rec1(t, w - min(w, A - a), a + min(w, A - a));

    rec1(t + min(a, T - t), w, a - min(a, T - t));
    rec1(t + min(w, T - t), w - min(w, T - t), a);
}

int main() {
    int N;
    cin >> N;

    for (int w = 0; w < N; ++w){
        int W, n;
        cin >> W >> T >> n;

        if (n == 0) cout << min(W, T) << '\n';
        if (n == 1){
            int a;
            cin >> a;
            A = a;

            possible = vi (T+1, 0);
            visited1 = vvi(W+1, vi(a+1, 0));
            rec1(0, W, 0);

            bool first = true;
            for (int i = 1; i <= T; ++i){
                if (not possible[i]) continue;

                if (first) first = false;
                else cout << ',';

                cout << i;
            }
            cout << '\n';
            
        }
        if (n == 2){
            int a, b;
            cin >> a >> b;
            A = a; B = b;

            possible = vi (T+1, 0);
            visited = vvvi(W+1, vvi(a+1, vi(b+1, 0)));
            rec(0, W, 0, 0);

            bool first = true;
            for (int i = 1; i <= T; ++i){
                if (not possible[i]) continue;

                if (first) first = false;
                else cout << ',';

                cout << i;
            }
            cout << '\n';
        }
    }
}