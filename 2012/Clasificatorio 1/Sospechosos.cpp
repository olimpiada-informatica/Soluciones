#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;

    cin >> n;
    vector <string> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    cin >> m;
    vector <string> B(m);
    for (int i = 0; i < m; ++i) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    string last = "";

    int i = 0, j = 0;
    while (i < A.size() and j < B.size()){
        if (A[i] == last) ++i;
        else if (A[i] == B[j]){
            cout << A[i] << '\n';
            last = A[i];
            ++i;
            ++j;
        }
        else if (A[i] < B[j]) ++i;
        else ++j;
    }
}