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

int main (){
    int T;
    cin >> T;

    for (int w = 0; w < T; ++w){
        int x;
        cin >> x;

        string s;
        if (x >= 1e9) {
            s = to_string(x);
            reverse(s.begin(), s.end());
        }
        else {
            while (x > 0){
                int digit = x%2;
                x /= 2;
                s.push_back('0' + digit);
            }
        }

        int n = s.size();
        int m = n;

        for (int i = n-1; i >= 0; --i){
            if (s[i] == '1') m = i + 1;
        }

        cout << int(90 - 180 *double(m-1)/(n-1)) << endl;
    }
}