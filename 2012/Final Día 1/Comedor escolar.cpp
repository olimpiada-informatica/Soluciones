#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <set>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
typedef vector <vvvvi> vvvvvi;

int main (){
    int N;
    cin >> N;

    for (int w = 0; w < N; ++w){
        int t, k;
        cin >> t >> k;

        int sum = 0;
        for (int i = 0; i < k; ++i){
            int x;
            cin >> x;
            sum += x;
        }

        cout << t/sum << endl;
    }
}