#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvvvi> vvvvvi;

vi V;
vector <double> W;

bool possible(double c){
    double temperatura = 5;
    int last = 0;

    for (int i = 0; i < V.size(); ++i){
        temperatura = max(double(5), temperatura - 0.1*(V[i]-last));

        if (c < W[i]) return false;
        if (temperatura > 10) return false;
        double vg = W[i];
        double vj = c - vg;

        temperatura = (temperatura * vj + 25 * vg)/c;
        last = V[i];
    }
    return true;
}

int main (){
    cout.setf(ios::fixed);
    cout.precision(2);
    int n;
    while (cin >> n){
        V = vi(n);
        W = vector <double> (n);

        char c;
        for (int i = 0; i < n; ++i){
            int h, m;
            cin >> h >> c >> m;
            V[i] = m + h*60;
        }
        for (int i = 0; i < n; ++i) cin >> W[i];


        double left = 0, right = 21;
        while (left + 0.0001 < right){
            double mid = (left + right)/2;

            if (possible(mid)) right = mid;
            else left = mid + 0.0001;
        }

        if (possible(left-0.0001)) left -= 0.0001;
        if (not possible(left)) left += 0.0001; 
        cout << left << endl;
    }
}