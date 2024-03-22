#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int a[N], p[N];
bool visitado[N];
vector<pair<int, int>> opers;

void operar(int x, int y){
  if (x != y){
    opers.emplace_back(x, y);
    a[x] ^= a[y];
  }
}

void cambiar(int x, int y){
  operar(x, y);
  operar(y, x);
  operar(x, y);
}

int main(){
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  
  for (int mask = 1; mask < (1 << 21); mask++){
    int x = 0;
    for (int i = 0; i < 21; i++){
      if (mask >> i & 1){
        x ^= a[i + 1];
      }
    }

    if (x == 0){
      int x1 = 0;

      for (int i = 0; i < 21; i++){
        if (!(mask >> i & 1)){
          continue;
        }

        if (x1 == 0){
          x1 = i + 1;
        }
        else{
          operar(x1, i + 1);
        }
      }

      cambiar(1, x1);

      break;
    }
  }

  vector<int> orden(n);
  iota(orden.begin(), orden.end(), 1);

  stable_sort(orden.begin(), orden.end(),
              [&] (int x, int y){
                return a[x] < a[y];
              });
  
  for (int i = 0; i < n; i++){
    p[orden[i]] = i + 1;
  }

  vector<vector<int>> ciclos;

  for (int i = 1; i <= n; i++){
    if (visitado[i]){
      continue;
    }

    vector<int> ciclo;
    int v = i;
    while (!visitado[v]){
      visitado[v] = 1;
      ciclo.push_back(v);
      v = p[v];
    }

    reverse(ciclo.begin(), ciclo.end());

    if (ciclo.size() > 1){
      ciclos.push_back(ciclo);
    }
  }

  if (ciclos.size() <= 200){
    for (auto c : ciclos){
      c.push_back(1);
      int prv = 1;
      for (auto v : c){
        operar(prv, v);
        operar(v, prv);
        prv = v;
      }
    }
  }
  else{
    for (auto c : ciclos){
      for (int i = 1; i < c.size(); i++){
        cambiar(c[i - 1], c[i]);
      }
    }
  }

  assert(is_sorted(a + 1, a + n + 1));

  cout << opers.size() << endl;
  for (auto [x, y] : opers){
    cout << x << " " << y << endl;
  }
}
