// Solución oficial esperada para el problema completo (todas las subtareas).
// Utiliza un diccionario (unordered_map) para asociar rápidamente a cada persona con sus pagos.
// Tras calcular lo que cada uno debería haber pagado, los divide en dos listas: deudores y acreedores.
// Luego, aplica un algoritmo voraz (greedy) emparejando a un deudor con un acreedor y transfiriendo
// el máximo dinero posible entre ellos. Como en cada paso al menos una persona salda su cuenta 
// por completo y sale de la lista, el algoritmo garantiza matemáticamente un máximo de n-1 transferencias.

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Transferencia {
  string envia;
  string recibe;
  long long cuantia;
};

void resolver() {
  int n, m;
  cin >> n >> m;
  
  vector<string> nombres(n);
  unordered_map<string, int> nombre_a_id;
  
  // Leemos los voluntarios y les asignamos un ID secuencial
  for (int i = 0; i < n; i++) {
    cin >> nombres[i];
    nombre_a_id[nombres[i]] = i;
  }
  
  vector<long long> pagado(n, 0);
  long long suma_total = 0;
  
  // Leemos los pagos
  for (int i = 0; i < m; i++) {
    string persona;
    long long cantidad;
    cin >> persona >> cantidad;
    
    pagado[nombre_a_id[persona]] += cantidad;
    suma_total += cantidad;
  }
  
  // Lo que cada uno debería haber pagado idealmente
  long long por_persona = suma_total / n;
  
  // Separamos en quienes deben dinero y a quienes les deben
  // Guardamos pares: {nombre_persona, cantidad_absoluta}
  vector<pair<string, long long>> deudores;
  vector<pair<string, long long>> acreedores;
  
  for (int i = 0; i < n; i++) {
    long long balance = pagado[i] - por_persona;
    if (balance < 0) {
      deudores.push_back({nombres[i], -balance}); // Guardamos en positivo lo que debe
    } else if (balance > 0) {
      acreedores.push_back({nombres[i], balance});
    }
  }
  
  vector<Transferencia> transferencias;
  
  // Algoritmo Greedy
  while (!deudores.empty() && !acreedores.empty()) {
    auto& [deudor_nombre, deudor_cantidad] = deudores.back();
    auto& [acreedor_nombre, acreedor_cantidad] = acreedores.back();
    
    // La transferencia será el mínimo entre lo que el deudor puede dar y el acreedor puede recibir
    long long cantidad = min(deudor_cantidad, acreedor_cantidad);
    
    transferencias.push_back({deudor_nombre, acreedor_nombre, cantidad});
    
    // Actualizamos los saldos
    deudor_cantidad -= cantidad;
    acreedor_cantidad -= cantidad;
    
    // Si alguien se queda a cero, lo sacamos de la lista
    if (deudor_cantidad == 0) deudores.pop_back();
    if (acreedor_cantidad == 0) acreedores.pop_back();
  }
  
  // Imprimimos la salida
  cout << transferencias.size() << "\n";
  for (const auto& [envia, recibe, cuantia] : transferencias) {
    cout << envia << " " << recibe << " " << cuantia << "\n";
  }
}

int main() {
  
  int t; cin >> t;
  while (t--) {
    resolver();
  }
  
  return 0;
}
