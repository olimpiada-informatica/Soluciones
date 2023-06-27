#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<string> tablero;
vector<int> quitadosArriba, quitadosAbajo, quitadosIzq, quitadosDer;
vector<vector<bool>> explorado;
int n;

void actualizarExplorado(int fila, int columna) {
    while(quitadosArriba[columna] < n) {
        if (explorado[quitadosArriba[columna]][columna]) {
            quitadosArriba[columna]++;
        } else break;
    }
    while(quitadosAbajo[columna] < n) {
        if (explorado[n-1-quitadosAbajo[columna]][columna]) {
            quitadosAbajo[columna]++;
        } else break;
    }
    while(quitadosIzq[fila] < n) {
        if (explorado[fila][quitadosIzq[fila]]) {
            quitadosIzq[fila]++;
        } else break;
    }
    while(quitadosDer[fila] < n) {
        if (explorado[fila][n-1-quitadosDer[fila]]) {
            quitadosDer[fila]++;
        } else break;
    }
}

bool esPosible() {
    queue<int> Q;
    quitadosArriba.assign(n, 0);
    quitadosAbajo.assign(n, 0);
    quitadosIzq.assign(n, 0);
    quitadosDer.assign(n, 0);
    explorado.assign(n, vector<bool>(n, false));
    int visitados = 0;
    for (int fila = 0; fila < n; fila++) {
        if (tablero[fila][0] == 'L') {
            Q.push(n*fila);
            explorado[fila][0] = true;
            visitados++;
        }
        if (tablero[fila][n-1] == 'R') {
            Q.push(n*fila + n-1);
            explorado[fila][n-1] = true;
            visitados++;
        }
    }
    for (int columna = 0; columna < n; columna++) {
        if (tablero[0][columna] == 'U') {
            Q.push(columna);
            explorado[0][columna] = true;
            visitados++;
        }
        if (tablero[n-1][columna] == 'D') {
            Q.push(n*(n-1) + columna);
            explorado[n-1][columna] = true;
            visitados++;
        }
    }
    int filaActual, columnaActual;
    while(!Q.empty()) {
        filaActual = Q.front() / n;
        columnaActual = Q.front() % n;
        Q.pop();
        actualizarExplorado(filaActual, columnaActual);
        if (quitadosIzq[filaActual] < n
            && tablero[filaActual][quitadosIzq[filaActual]] == 'L'
            && !explorado[filaActual][quitadosIzq[filaActual]]) {
            explorado[filaActual][quitadosIzq[filaActual]] = true;
            visitados++;
            Q.push(n*filaActual + quitadosIzq[filaActual]);
            actualizarExplorado(filaActual, quitadosIzq[filaActual]);
        }
        if (quitadosDer[filaActual] < n
            && tablero[filaActual][n-1-quitadosDer[filaActual]] == 'R'
            && !explorado[filaActual][n-1-quitadosDer[filaActual]]) {
            explorado[filaActual][n-1-quitadosDer[filaActual]] = true;
            visitados++;
            Q.push(n*filaActual + n-1-quitadosDer[filaActual]);
            actualizarExplorado(filaActual, quitadosDer[filaActual]);
        }
        if (quitadosArriba[columnaActual] < n
            && tablero[quitadosArriba[columnaActual]][columnaActual] == 'U'
            && !explorado[quitadosArriba[columnaActual]][columnaActual]) {
            explorado[quitadosArriba[columnaActual]][columnaActual] = true;
            visitados++;
            Q.push(n*quitadosArriba[columnaActual] + columnaActual);
            actualizarExplorado(quitadosArriba[columnaActual], columnaActual);
        }
        if (quitadosAbajo[columnaActual] < n
            && tablero[n-1-quitadosAbajo[columnaActual]][columnaActual] == 'D'
            && !explorado[n-1-quitadosAbajo[columnaActual]][columnaActual]) {
            explorado[n-1-quitadosAbajo[columnaActual]][columnaActual] = true;
            visitados++;
            Q.push(n*(n-1-quitadosAbajo[columnaActual]) + columnaActual);
            actualizarExplorado(n-1-quitadosAbajo[columnaActual], columnaActual);
        }
    }
    return visitados == n*n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        tablero = vector<string>(n);
        for (int i = 0; i < n; i++) {
            cin >> tablero[i];
        }
        if (esPosible()) {
            cout << "POSIBLE\n";
        } else {
            cout << "IMPOSIBLE\n";
        }
    }
    return 0;
}
