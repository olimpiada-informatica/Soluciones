#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    int k = 1;
    for (int i = 0; i < n; i++){
        for (int j = i-1; j >= 0; j--){
            v[j][i] = k++;
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
