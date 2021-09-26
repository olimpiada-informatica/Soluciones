#include <iostream>
#include <vector>

using namespace std;
typedef vector <int> vi;

vector <string> M;

int solve(int n, int m){
    int total = 0;

    for (int i = 0; i < n; ++i){
        for (int j = 0; j < m - 2; ++j) {
            if (M[i][j] == 'O' and M[i][j+1] == 'I' and M[i][j+2] == 'E') ++total;
            if (M[i][j] == 'E' and M[i][j+1] == 'I' and M[i][j+2] == 'O') ++total;
        }
    }

    for (int i = 0; i < n - 2; ++i){
        for (int j = 0; j < m; ++j) {
            if (M[i][j] == 'O' and M[i+1][j] == 'I' and M[i+2][j] == 'E') ++total;
            if (M[i][j] == 'E' and M[i+1][j] == 'I' and M[i+2][j] == 'O') ++total;
        }
    }

    for (int i = 0; i < n - 2; ++i){
        for (int j = 0; j < m - 2; ++j) {
            if (M[i][j] == 'O' and M[i+1][j+1] == 'I' and M[i+2][j+2] == 'E') ++total;
            if (M[i][j] == 'E' and M[i+1][j+1] == 'I' and M[i+2][j+2] == 'O') ++total;
        }
    }

    for (int i = 2; i < n; ++i){
        for (int j = 0; j < m - 2; ++j) {
            if (M[i][j] == 'O' and M[i-1][j+1] == 'I' and M[i-2][j+2] == 'E') ++total;
            if (M[i][j] == 'E' and M[i-1][j+1] == 'I' and M[i-2][j+2] == 'O') ++total;
        }
    }

    return total;
}


int main () {
    int n, m;
    while (cin >> n >> m){
        M = vector <string> (n);
        for (int i = 0; i < n; ++i) cin >> M[i];

        cout << solve(n, m) << endl;
    }
}