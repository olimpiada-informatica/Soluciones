// Solución óptima O((N + M) log N): Implementa un algoritmo de Dijkstra sobre el grafo invertido,
// partiendo desde la estación de destino. Para las paradas rojas (Ariadna minimiza),
// se propaga inmediatamente el tiempo mínimo descubierto hacia atrás.
// Para las paradas verdes (Darío maximiza), se cuenta el grado de salida original ("vidas")
// y solo se añade el nodo a la cola de prioridad con el tiempo máximo cuando se han 
// evaluado y garantizado todas sus posibles rutas finitas (vidas == 0). 
// Los ciclos o callejones sin salida conservan vidas > 0, resultando en INFINITO.


#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<vector<pair<int,int>>> from(n);

    vector<bool> visto(n,0);

    vector<int> vidas(n);
    vector<int> peortiempo(n);
    // estos dos solo para los verdes

    while (m--){
        int a,b,d;
        cin >> a >> b >> d;
        a--;b--;
        from[b].push_back({a,d});
        if (s[a]=='V') vidas[a]++;
    }

    priority_queue<pair<int,int>> cola;

    cola.push({0,n-1});

    while (cola.size()){
        auto [d,x] = cola.top();
        int d1=-d;
        cola.pop();

        if (!visto[x]){
            visto[x]=1;
            if (x==0){
                cout << d1 << endl;
                return;
            }
            for (auto [y,d2]:from[x]){
                if (s[y]=='R') cola.push({-d1-d2,y});
                else{
                    vidas[y]--;
                    peortiempo[y]=max(peortiempo[y],d1+d2);
                    if (vidas[y]==0) cola.push({-peortiempo[y],y});
                }
            }
        }
    }
    cout << "INFINITO" << endl;
    return;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
