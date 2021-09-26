#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <string>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

int main (){
    int n;
    cin >> n;

    string s;
    getline(cin, s);

    map <string, int> M;
    vector <string> A;
    A.push_back("USD");
    M["USD"] = 0;

    for (int i = 0; i < n; ++i){
        getline(cin, s);

        stringstream ss(s);
        int value;

        ss >> value;
        string a = "USD";
        ss >> a;

        if (M.find(a) == M.end()) A.push_back(a);
        M[a] += value;
    }

    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << ": " << M[A[i]] << endl;
    }
}