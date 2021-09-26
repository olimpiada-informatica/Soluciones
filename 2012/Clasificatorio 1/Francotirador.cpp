#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;


int main(){
    cout.setf(ios::fixed);
    cout.precision(4);

    int n;
    cin >> n;

    for (int cases = 0; cases < n; ++cases){
        double vb, vs, t;
        cin >> vb >> vs >> t;

        cout << t / (1000*abs(1/vb - 1/vs)) << endl;
    }   
}