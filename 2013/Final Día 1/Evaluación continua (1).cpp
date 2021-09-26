#include <iostream>
#include <vector>

using namespace std;

vector <int> V;

int consecutius(int j, int k){
    int sum = 0;

    for (int i = j; i < k+j; ++i) sum += V[i];

    return sum;
}

int main(){

    int n, k;
    while (cin >> n >> k){
        V.clear();

        for (int i = 0; i < n; ++i){
            int a;
            cin >> a;
            V.push_back(a);
        }
        int sum = (consecutius(0, k));
        int tic = sum;

        for (int j = 1; j < n-k+1; ++j){
            tic = tic - V[j-1] + V[j+k-1];
            if (tic > sum) sum = tic;
        }
        cout << sum << endl;
    }
}