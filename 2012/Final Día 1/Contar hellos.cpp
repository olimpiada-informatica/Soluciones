#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;

int main (){
    int n, total = 0;
    cin >> n;

    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;

        if (s == "hello") ++total;
    }

    cout << total << endl;
}