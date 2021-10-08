#include<iostream>
#include<string>
using namespace std;

typedef long long int ll;


string rec(int a) {
    if(a == 0) {
        return "1";
    }
    else {
        string s = rec(a-1);
        int ss = s.size();
        char v = s[0];
        int t = 1;
        string sol = "";
        for(int i=1; i < ss; i++) {
            if(s[i] == v) {
                t++;
            }
            else {
                sol += char(t+'0');
                sol += v;
                v = s[i];
                t = 1;
            }
        }
        sol += char(t+'0');
            sol += v;

        return sol;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << rec(n) << endl;
}
