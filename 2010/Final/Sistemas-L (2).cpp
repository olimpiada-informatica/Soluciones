#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <map>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;

const int alfa = '~';
vi times(alfa + 1, 0);
vvi multimes;

map <char, int> M;
vector <string> repl;
vector <string> operation;

string change2(string& s){
    string ans = "";
    for (int i = 0; i < s.size(); ++i){
        ans += repl[M[s[i]]];
    }

    return ans;
}

void change(){
    vi aux(alfa + 1, 0);

    for (int i = 0; i <= alfa; ++i){
        if (times[i] == 0) continue; 
        int index = M[char(i)];

        for (int j = 0; j <= alfa; ++j){
            if (multimes[index][j] == 0) continue;

            aux[j] += times[i] * multimes[index][j];
        }
    }

    times = aux;
}

ll sum(){
    ll ans = 0;
    for (int i = 0; i <= alfa; ++i) ans += times[i];
    return ans;
}

ll mida(string& s, int k, int end){
    fill(times.begin(), times.end(), 0);

    for (int i = 0; i < end; ++i) ++times[s[i]];
    for (int i = 0; i < k; ++i) change();
    return sum();
}

void print(string& s, int k, ll l, ll r){
    if (k == 0){
        for (int i = l; i <= r; ++i) cout << operation[M[s[i]]] << '\n';
        return;
    }

    int left = 0, right = s.size();

    while (left + 1 < right){
        int middle = (left + right)/2;
        ll amount = mida(s, k, middle);

        if (amount > l) right = middle - 1;
        else left = middle;
    }


    ll possible_amount = mida(s, k, left + 1);
    if (possible_amount <= l) ++left;

    ll amount = mida(s, k, left);
    ll amount2 = mida(s, k,
     right);


    while (amount2 < r) {
        ++right;
        amount2 = mida(s, k, right);
    }

    string aux;
    for (int i = left; i <= right; ++i) aux.push_back(s[i]);

    string news = change2(aux);

    print(news, k-1, l - amount, r - amount);
}

int main (){
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) ++times[s[i]];

    int n, k;
    cin >> n >> k;

    repl = vector <string>(n);
    operation = vector <string>(n);

    string smth;
    getline(cin, smth);

    for (int i = 0; i < n; ++i){
        getline(cin, smth);
        char c;

        stringstream ss(smth);
        ss >> c;

        M[c] = i;
        string rep;
        ss >> rep;

        string op = "";
        string a;

        while (ss >> a){
            if (not op.empty()) op.push_back(' ');
            op += a;
        }

        vi aux(alfa + 1, 0);
        for (int i = 0; i < rep.size(); ++i) ++aux[rep[i]];
        multimes.push_back(aux);

        repl[i] = rep;
        operation[i] = op;
    }

    
    ll l, r;
    cin >> l >> r;

    for (int i = 0; i < k; ++i) change();
    cout << sum() << endl;

            
    print(s, k, l, r);
}