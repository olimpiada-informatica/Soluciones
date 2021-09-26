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
    int n;
    cin >> n;

    for (int i = 1; i < n; ++i){
        if (i % 4 == 0) cout << "Ziuuu-Paff!,";
        else cout << "Bam!,";

        if (i % 5 == 0) cout << endl;
    }

    cout << "Ziuuu-Paff!" << endl;
}