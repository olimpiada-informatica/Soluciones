#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>  

using namespace std;
typedef pair <int, int> ii;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

int n, p;

int power (int m, int x){
    int ans = 1;
    for (int i = 0; i < x; ++i) ans *= m;
    return ans;
}

bool valid1(int x){
    string s = to_string(x);
    for (int i = 1; i < s.size(); ++i){
        if (s[i] == '0' and (s[i-1] != '1') and s[i-1] != '2') return false;
    }
    return true;
}

bool valid2(int x){
    string s = to_string(x);
    for (int i = 1; i < s.size(); ++i){
        if (s[i-1] == '2' and (s[i] > '2' and s[i] < '7')) return false;
        if (s[i-1] == '1' and s[i] > '2') return false;
        if (s[i] == '0' and (s[i-1] != '1') and s[i-1] != '2') return false;
        
        if (i < s.size() - 1 and s[i-1] > '0' and s[i-1] < '3' and s[i] > '0' and s[i] < '3' and s[i+1] != '0') return false;
        if (i == s.size() - 1 and s[i-1] > '0' and s[i-1] < '3' and s[i] > '0' and s[i] < '3') return false;        
    }
    return true;
}

void rec1(){
    int total = 0;

    int p1 = power(10, n-1);
    int p2 = power(10, n);

    for (int i = p1; i < p2 and total < p; ++i){
        if (not valid1(i)) continue;

        cout << i << '\n';
        ++total;
    }
}   

void rec2(){
    int total = 0;

    int p1 = power(10, n-1);
    int p2 = power(10, n);

    for (int i = p1; i < p2 and total < p; ++i){
        if (not valid2(i)) continue;

        cout << i << '\n';
        ++total;
    }
}



int main (){
    char c;
    
    cin >> n >> c >> p;
    if (n == 1){
        for (int i = 1; i < 10 and i <= p; ++i) cout << i << '\n';
    }
    else if (c == 't') rec1();
    else rec2();
} 