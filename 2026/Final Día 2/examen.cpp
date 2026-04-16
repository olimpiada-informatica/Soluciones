// Solución oficial óptima O(N log N): Ordena los valores de forma descendente y evalúa 
// tomar los mejores 'm' elementos (desde k hasta N). Utiliza una técnica de dos punteros 
// donde la variable 'quietos' (elementos que ya superan el umbral 'mid') avanza monótonamente 
// sin reiniciarse, lo que permite calcular el coste para cada 'm' en O(1) amortizado.

#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    double D;
    cin >> n >> k >> D;

    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];

    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());

    vector<int> pref(n+1);
    for (int i=0;i<n;i++) pref[i+1]=pref[i]+v[i];

    double bestans=2e9;

    int quietos=0; // cuenta cuantos tios ya no incremento
    for (int m=k;m<=n;m++){ // m es cuantos tios considero
        double mid;
        while (quietos<m){ // en quietos=k-1 ambos son iguales
            if (quietos<k) mid=D/(m-k+1);
            else mid=(D-(pref[quietos]-pref[k-1]))/(m-quietos);
            
            if (v[quietos]>mid) quietos++;
            else break;
        }
        double ans=mid*(m-quietos)-(pref[m]-pref[quietos]);
        // cerr << m << ": " << ans << '\n';
        bestans=min(bestans,ans);
    }
    cout << fixed << setprecision(6) << bestans << '\n';
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}
