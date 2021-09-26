#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

vvi T;
vi visited(1048576);
int n, ND;

int transform(string& s, bool one){
    int ans = 0;
    if (one) ++ans;
    for (int i = 0; i < s.size(); ++i){
        ans *= 2;
        ans += s[i] - 'a';
    }

    return ans;
}

int words(int start, int digits){
    queue <vi> Q;
    fill (visited.begin(), visited.end(), 0);
    Q.push({0, start, digits});
    
    visited[start] = 1;

    while (not Q.empty()){
        vi aux = Q.front(); Q.pop();

        int d = aux[0];
        int w = aux[1];
        int digits = aux[2];

        for (int i = 0; i < n; ++i){
            if (w < T[i][0]) continue;

            int pre = 0, med = 0, last = w;
            int m = T[i][2], dg = digits;

            for (int k = 0; k < T[i][2]; ++k){
                int one = last >> dg;
                if (one) last -= (1 << dg);

                --dg;
                med <<= 1;
                med += one;
            }


            while (dg >= 0){
                int one = last >> dg;
                if (one) last -= (1 << dg);

                --dg;
                med <<= 1;
                med += one;

                one = med >> m;
                if (one) med -= (1 << m);
                pre <<= 1;
                pre += one;

                if (med == T[i][0]){
                    int number = (pre << T[i][3]) + T[i][1];
                    
                    number <<= (dg + 1);
                    number += last;
                    
                    if (number > ND) continue;
                    if (number == ND) return d + 1;
                    if (d < 8 and not visited[number]){
                        visited[number] = 1;
                        Q.push({d+1, number, digits + T[i][3] - T[i][2]});
                    }
                }   
            }
        }
    }

    return 10;
}

void solve(int start, int digits){
    if (start == ND) {
        cout << "solucion en 0 pasos\n";
        return;
    }
        
    if (n == 0){
        cout << "sin solucion\n";
        return;
    }

    int ans = words(start, digits);
    if (ans == 1) cout << "solucion en "<< ans <<" paso\n";
    else if (ans < 10) cout << "solucion en "<< ans <<" pasos\n"; 
    else cout << "sin solucion\n";
}

int main (){
    string a, b;
    int caso = 1;
    
    while (cin >> a >> b){
        int start = transform(a, true);
        ND = transform(b, true);
        
        cin >> n;
        T = vvi(n, vi(4));

        for (int i = 0; i < n; ++i){
            string x, y;
            cin >> x >> y;

            T[i] = {transform(x, false), transform(y, false), (int)x.size(), (int)y.size()};
        }

        cout << "Caso #" << caso++ << ": ";
        solve(start, a.size());
    }
}
