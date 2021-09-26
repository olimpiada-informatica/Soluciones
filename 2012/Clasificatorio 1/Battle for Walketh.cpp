#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef vector <double> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

int HP1, HP2, damage1, damage2, trials1, trials2, auto1, auto2;
double p1, p2;
vvvvi dp;

double rec(int h1, int h2, int left, int first){
    if (h1 <= 0) return 0;
    if (h2 <= 0) return 1;

    double& ans = dp[h1][h2][left][first];
    if (ans != -1) return ans;

    if (first == 0){
        if (left == 1) {
            ans = p1*(1 - rec(h2 - damage1, h1, trials2, 1));
            if (p1 < 0.995) ans += (1 - p1)*(1 - rec(h2, h1 - auto1, trials2, 1));
        }
        else {
            ans = p1 * rec(h1, h2 - damage1, left-1, first);
            if (p1 < 0.995) ans += (1 - p1) * rec(h1 - auto1, h2, left-1, first);
        }
    }
    else {
        if (left == 1) {
            ans = p2*(1 - rec(h2 - damage2, h1, trials1, 0));
            if (p2 < 0.995) ans += (1 - p2)*(1 - rec(h2, h1 - auto2, trials1, 0));
        }
        else {
            ans = p2 * rec(h1, h2 - damage2, left-1, first);
            if (p2 < 0.995) ans += (1 - p2) * rec(h1 - auto2, h2, left-1, first);
        }
    }

    return ans; 
}

double rec2(int h1, int h2, int left, int first){
    if (h1 <= 0) return 0;
    if (h2 <= 0) return 1;

    double& ans = dp[h1][h2][left][first];
    if (ans != -1) return ans;

    if (first == 0){
        if (left == trials1){
            double pwin = 0;
            double p = 1;
            for (int i = trials1-1; i > 0; --i){
                pwin += p*p1 * rec2(h1, h2 - damage1, i, 0);
                p *= (1 - p1);
            }
            pwin += p*p1*(1 - rec2(h2 - damage1, h1, trials2, 1));
            p *= (1 - p1);


            for (int i = trials2-1; i > 0; --i){
                pwin +=  p*p2 * (1 - rec2(h2, h1 - damage2, i, 1));
                p *= (1 - p2);
            }

            pwin += p*p2*rec2(h1 - damage2, h2, trials1, 0);
            p *= (1 - p2);

            return ans = pwin/(1 - p);
        }

        if (left == 1) ans = p1*(1 - rec2(h2 - damage1, h1, trials2, 1)) + (1 - p1)*(1 - rec2(h2, h1 - auto1, trials2, 1));
        else ans = p1 * rec2(h1, h2 - damage1, left-1, first) + (1 - p1) * rec2(h1 - auto1, h2, left-1, first);
    }
    else {
        if (left == 1) ans = p2*(1 - rec2(h2 - damage2, h1, trials1, 0)) + (1 - p2)*(1 - rec2(h2, h1 - auto2, trials1, 0));
        else ans = p2 * rec2(h1, h2 - damage2, left-1, first) + (1 - p2) * rec2(h1 - auto2, h2, left-1, first);
    }

    return ans; 
}

double power(double x, int n){
    double ans = x;

    for (int i = 1; i < n; ++i) ans *= x;
    return ans;
}

int main(){
    string s;
    char c;

    while (cin >> s){
        cin >> HP1 >> s >> damage1 >> c >> trials1 >> c >> auto1 >> c >> p1 >> c;
        cin >> s >> HP2 >> s >> damage2 >> c >> trials2 >> c >> auto2 >> c >> p2 >> c;

        int maxh = max(HP1, HP2) + 1;
        int maxt = max(trials1, trials2) + 1;
        dp = vvvvi(maxh, vvvi(maxh, vvi(maxt, vi(2, -1)))); 
        
        p1/=100; p2/=100;

        if (auto1 != 0 or auto2 != 0 or p1 > 0.995 or p2 > 0.995){
            double probability = rec(HP1, HP2, trials1, 0);
            cout <<  int(0.5 + 100*probability) << endl;    
        }
        else {
            double probability = rec2(HP1, HP2, trials1, 0);
            cout << int(0.5 + 100*probability) << endl;
        }
    }
}