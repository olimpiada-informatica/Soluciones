#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <cmath>  

using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

vector <string> M;
vvi precalc;
vvi advanc;
int maxrobot = 0;
int n, m;

int solve(string robots){
    int total = 0;
    if (robots == "H"){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (j == 0 and M[i][j] == '.') ++total;
                if (j > 0 and M[i][j] == '.' and M[i][j-1] == 'X') ++total;
            }
        }
    }
    else {
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (i == 0 and M[i][j] == '.') ++total;
                if (i > 0 and M[i][j] == '.' and M[i-1][j] == 'X') ++total;
            }
        }
    }

    return total;
}

vvi dp;

int rec(int pos, int bit);

void query(vi& bits, vi& num, int pos, int& ans){
    int cost = 0;
    vi vertical(n, 0);

    int index = 0;
    for (int i = 0; i < num.size(); ++i){
        if (num[i] == 1) ++index;
        else {
            ++cost;
            for (int j = 0; j < num[i]; ++j) {
                if (M[index][pos] == 'X') return;
                vertical[index++] = 1;
            }
        }
    }

    int nextbits = 0;
    int powers = 1;

    for (int i = n-1; i >= 0; --i){
        if (not vertical[i]) {
            if (M[i][pos] != 'X'){
                if (bits[i] == 0) ++cost;
                nextbits += powers; 
            } 
        }
        powers <<= 1;
    }

    ans = min(ans, cost + rec(pos + 1, nextbits));
}

void findall(vi& bits, vi& num, int pos, int& ans, int sum){
    if (sum == n) {
        query(bits, num, pos, ans);
        return;
    }

    for (int i = 1; i <= n - sum; ++i){
        num.push_back(i);
        findall(bits, num, pos, ans, sum + i);
        num.pop_back();
    }
}   



int rec(int pos, int bit){
    int savebit = bit;

    if (pos == m) return 0;

    int& ans = dp[pos][bit];
    if (ans != -1) return ans;
    ans = 1e3;

    vi bits(n, 0);
    
    for (int i = n-1; i >= 0; --i){
        if (bit & 1) bits[i] = 1;
        bit >>= 1;
    }

    vi num = {};
    findall(bits, num, pos, ans, 0);

    return ans;
}


void solve2(){
    dp = vvi(m, vi(1 << n, -1));
    cout << rec(0, 0) << endl;
}

int main() {
    int t;
    cin >> t;

    for (int w = 0; w < t; ++w){
        string robots;
        cin >> robots;

        cin >> n >> m;
        M = vector <string>(n);
        for (int i = 0; i < n; ++i) cin >> M[i];

        if (robots.size() == 1) cout << solve(robots) << '\n';
        else solve2();
    }
}