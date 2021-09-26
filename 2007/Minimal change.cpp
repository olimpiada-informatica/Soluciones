#include <iostream>
#include <vector>

using namespace std;
typedef vector <int> vi;

const vi coins = {200, 100, 50, 20, 10, 5, 2, 1};

int main () {
    int n;
    while (cin >> n){
        if (n == -1) break;

        cout << n << ": ";

        int total = 0;
        for (int i = 0; i < coins.size(); ++i){
            total += n/coins[i];
            n %= coins[i];
        }

        cout << total << endl;
    }
}