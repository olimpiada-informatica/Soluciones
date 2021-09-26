#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvvvi> vvvvvi;

int main (){
    cout.setf(ios::fixed);
    cout.precision(4);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i){
        double d, p, h, b;
        cin >> d >> p >> h >> b;

        h = abs(h-p);
        double x = sqrt(p*p - h*h);
        
        cout << d + x + b << '\n';
    }
}