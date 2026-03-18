#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {


  int T;
  if (!(cin >> T)) return 0;
  
  for (int tc = 0; tc < T; ++tc) {
    
    int D, C, N;
    cin >> D >> C >> N;
    
    vector<int> viewers(C + 1);
    vector<int> leadTime(C + 1, 0);
    
    for (int i = 1; i <= C; ++i)
      cin >> viewers[i];
    
    priority_queue<pair<int, int>> pq;
    for (int i = 1; i <= C; ++i)
      pq.push({viewers[i], i});
    
    auto getLeader = [&]() {
      while (true) {
        auto [aud, c] = pq.top();
        if (aud == viewers[c])
          return c;
        pq.pop();
      }
    };
    
    int currentLeader = getLeader();
    int lastMinute = 0;
    
    for (int i = 0; i < N; ++i) {
      int m, u;
      cin >> m >> u; // NUEVO FORMATO: Leer el minuto y la cantidad de actualizaciones
      
      // Contar minutos del líder anterior
      leadTime[currentLeader] += m - lastMinute;
      lastMinute = m;
      
      // NUEVO FORMATO: Leer y aplicar cambios iterando 'u' veces
      for (int j = 0; j < u; ++j) {
        int c, e;
        cin >> c >> e;
        viewers[c] = e;
        pq.push({viewers[c], c});
      }
      
      currentLeader = getLeader();
    }
    
    // Contar minutos desde la última actualización hasta el final
    leadTime[currentLeader] += D - lastMinute;
    
    // Preparar resultado
    vector<pair<int, int>> result;
    for (int i = 1; i <= C; ++i)
      if (leadTime[i] > 0)
        result.push_back({i, leadTime[i]});
    
    sort(result.begin(), result.end(), [](auto &a, auto &b) {
      if (a.second != b.second) return a.second > b.second;
      return a.first < b.first;
    });
    
    for (auto &p : result)
      cout << p.first << " " << p.second << "\n";
  }
  
  return 0;
}