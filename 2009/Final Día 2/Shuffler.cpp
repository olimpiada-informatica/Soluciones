#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

vvvi dp;
vi A, B;

int rec(int x, int y, int stack){
    if (x == A.size() and y == B.size()) return 0;
    
    int& ans = dp[x][y][stack];
    if (ans != -1) return ans;

    int putfs = 1e9, putsc = 1e9;

    int last;
    if (stack == 0) last = A[x-1];
    else last = B[y-1];
    
    if (x < A.size()){
        if (last >= A[x]) putfs = rec(x+1, y, 0);
        else putfs = (last - A[x]) * (last - A[x]) + rec(x+1, y, 0); 
    }

    if (y < B.size()){
        if (last >= B[y]) putsc = rec(x, y+1, 1);
        else putsc = (last - B[y]) * (last - B[y]) + rec(x, y+1, 1); 
    }

    return ans = min(putfs, putsc);
}   



int main (){
    int x;
    while (cin >> x){
        A.clear(); B.clear();

        while (x > 0) {
            A.push_back(x);
            cin >> x;
        }

        cin >> x;

        while (x > 0) {
            B.push_back(x);
            cin >> x;
        }

        dp = vvvi(A.size()+1, vvi(B.size()+1, vi(2, -1)));
        cout << min(rec(1, 0, 0), rec(0, 1, 1)) << '\n';
    }
}