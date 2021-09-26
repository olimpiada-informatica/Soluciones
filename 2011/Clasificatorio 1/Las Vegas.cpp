#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

vvi prob(1001, vi(11, -1));
vvi money(1001, vi(11, 0));

vi power = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int rec(int n, int r){
    if (n >= 1000) return power[r];
    if (r == 0) return 0;

    int& ans = prob[n][r];
    if (ans != -1) return ans;

    int index = 0;
    ans = 0;

    for (int i = 0; i <= n; ++i){
        int value = rec(n - i, r - 1) + rec(n + i, r - 1);

        if (value > ans){
            ans = value;
            index = i;
        }
    }

    money[n][r] = index;
    return ans;
}

int main () {
    int n, r;
    while (cin >> n >> r) {
        int num = rec(n, r);
        int den = power[r];

        int gc = gcd(num, den);

        cout << money[n][r] << " " << num/gc << "/" << den/gc << '\n';
    }
}