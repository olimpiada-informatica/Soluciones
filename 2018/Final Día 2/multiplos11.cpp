#include<iostream>
#include<vector>
#include<string>
using namespace std;

typedef long long int ll;

const int msum = 1e5;

int digit(char c) {
    return c-'0';
}

void caso() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> sumval = vector<ll>(11, 0);
    sumval[msum%11]=1;
    int sum = 0;
    int coef = 1;
    bool samedigit = true;
    for(int i=0; i < n; i++) {
        sum += digit(s[i])*coef;
        coef *=-1;
        sumval[(sum+msum)%11]++;
        if(i > 0 && s[i] != s[i-1]) samedigit = false;
    }
    ll sol;
    if(samedigit) {
         sumval = vector<ll>(2*msum, 0);

        sumval[msum]=1;
        sum = 0;
        coef = 1;
        for(int i=0; i < n; i++) {
            sum += digit(s[i])*coef;
            coef *=-1;
            sumval[sum+msum]++;
        }
        sol = 0;
        for(int i=0; i < 2*msum; i++) {
            sol += ((sumval[i])*(sumval[i]-1))/2;
        }
        cout << sol << endl;
        return;
    }

    sol = 0;
    for(int i=0; i < 11; i++) {
        sol += ((sumval[i])*(sumval[i]-1))/2;
    }
    cout << sol << endl;

}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i=0; i< t; i++) {
        caso();
    }
}
