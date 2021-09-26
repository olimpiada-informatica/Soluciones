#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long int ll;

int main (){
    int k, n;
    cin >> k >> n;

    int sum = 0;
    for (int i = 0; i < k; ++i){
        int x;
        cin >> x;

        sum += x/n;
    }

    cout << sum << endl;
}