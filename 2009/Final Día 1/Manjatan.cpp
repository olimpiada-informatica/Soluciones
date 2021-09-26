#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
 
using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

vvi calles;
vvi inter;
vvi cross;

void read_calles(int n){
    calles = vvi(n+1);
    inter = vvi(n+1);
    cross = vvi(n+1, vi(n+1, -1));

    vvi H, V;

    for (int i = 1; i <= n; ++i){
        int x1, y1, x2, y2, d;
        cin >> x1 >> y1 >> x2 >> y2 >> d;

        calles[i] = {x1, y1, x2, y2, d};
        if (x1 == x2) V.push_back({x1, y1, x2, y2, i});
        else          H.push_back({y1, x1, y2, x2, i});
    }
    
    sort(H.begin(), H.end());
    sort(V.begin(), V.end());

    for (int i = 0; i < H.size(); ++i){
        int pos1 = H[i][4];
        int x1 = min(H[i][1], H[i][3]);
        int x2 = max(H[i][1], H[i][3]);
        int y = H[i][0];

        for (int j = 0; j < V.size(); ++j){
            int pos2 = V[j][4];
            int y1 = min(V[j][1], V[j][3]);
            int y2 = max(V[j][1], V[j][3]);
            int x = V[j][0];

            if (x1 <= x and x2 >= x and y1 <= y and y2 >= y) inter[pos1].push_back(pos2);
        }
    }

    for (int j = 0; j < V.size(); ++j){
            int pos2 = V[j][4];
            int y1 = min(V[j][1], V[j][3]);
            int y2 = max(V[j][1], V[j][3]);
            int x = V[j][0];

            for (int i = 0; i < H.size(); ++i){
                int pos1 = H[i][4];
                int x1 = min(H[i][1], H[i][3]);
                int x2 = max(H[i][1], H[i][3]);
                int y = H[i][0];

            if (x1 <= x and x2 >= x and y1 <= y and y2 >= y) inter[pos2].push_back(pos1);
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 0; j < inter[i].size(); ++j){
            cross[i][inter[i][j]] = j;
        }
    }
}

ll distancia;
bool stop;

bool valid(vi& aux1, int calle, int direccion, int derecha){
    vi& aux = calles[calle];

    int part = direccion + derecha;
    if (part != 0) part = 1;

    if (aux1[1] == aux1[3]){
        int y = aux1[1];
        int y1 = min(aux[1], aux[3]);
        int y2 = max(aux[1], aux[3]);

        if (part and y1 == y) return false; 
        if (not part and y2 == y) return false;
    }
    else {
        int x = aux1[0];
        int x1 = min(aux[0], aux[2]);
        int x2 = max(aux[0], aux[2]);

        if (part and x2 == x) return false; 
        if (not part and x1 == x) return false;
    }

    if (aux.back() == 0) return true;

    bool increasing = (direccion + derecha != 0);
    if (aux[0] == aux[2]) increasing = not increasing;
    if (aux[0] > aux[2] or aux[1] > aux[3]) increasing = not increasing;
    
    return increasing;
}

void dist(int calle, int inicio, int final){
    int n = inter[calle].size();
    vi& aux = calles[calle];

    if (inicio > final) swap(inicio, final);

    if (inicio < -1) inicio = -1;
    if (final > n) final = n;

    int x1 = aux[0], y1 = aux[1], x2 = aux[2], y2 = aux[3];

    if (x1 > x2 or y1 > y2){
        swap(x1, x2);
        swap(y1, y2);
    }

    bool horiz = (y1 == y2);

    if (inicio >= 0){
        if (horiz) x1 = calles[inter[calle][inicio]][0];
        else y1 = calles[inter[calle][inicio]][1];
    }
    if (final < n){
        if (horiz) x2 = calles[inter[calle][final]][0];
        else y2 = calles[inter[calle][final]][1];
    }

    if (horiz) distancia += abs(x1 - x2);
    else distancia += abs(y1 - y2);
}

void update(int& calle, int& pos1, int& d, int pos2, int derecha){
    int newcalle = inter[calle][pos2];

    pos1 = cross[newcalle][calle];
    
    vi& aux = calles[newcalle];
    bool increasing = (d + derecha != 0);
    if (aux[0] == aux[2]) increasing = not increasing;
    
    d = 1;
    if (not increasing) d = -1;

    calle = newcalle;
}

void ejecutar(string& s, int& calle, int& pos1, int& d){
    int derecha = 1;
    if (s.back() == 'I') derecha = -1;
    s.pop_back();

    int avanzar = stoi(s);
    int pos2 = pos1 + d*avanzar;

    dist(calle, pos1, pos2);

    while (pos2 >= 0 and pos2 < inter[calle].size() 
                        and not valid(calles[calle], inter[calle][pos2], d, derecha)){
        pos2 += d;
        dist(calle, pos2 - d, pos2);
    }

    if (pos2 < 0 or pos2 >= inter[calle].size()) stop = true;
    else update(calle, pos1, d, pos2, derecha);
}

void solve_query(){
    distancia = 0;
    stop = false;

    int calle;
    cin >> calle;

    string instruccion;
    cin >> instruccion;

    vi& aux = calles[calle];

    int direccion = 1, posicion = -1;
    if (aux[0] > aux[2] or aux[1] > aux[3]) {
        direccion = -1;
        posicion = inter[calle].size();
    }
    
    if (inter[calle].size() > 0){
        if (direccion == 1){
            if (aux[0] == aux[2] and aux[1] == calles[inter[calle][0]][1]) ++posicion;
            if (aux[1] == aux[3] and aux[0] == calles[inter[calle][0]][0]) ++posicion;
        }
        else {
            if (aux[0] == aux[2] and aux[1] == calles[inter[calle].back()][1]) --posicion;
            if (aux[1] == aux[3] and aux[0] == calles[inter[calle].back()][0]) --posicion;
        }
    }

    while (instruccion != "0X"){
        if (not stop) ejecutar(instruccion, calle, posicion, direccion);
        cin >> instruccion;
    }

    if (not stop) dist(calle, posicion, direccion*4000);

    cout << distancia;
    if (stop) cout << '!';
    cout << '\n';
}


int main(){
    int n;
    cin >> n;

    read_calles(n);    

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) solve_query();
}
