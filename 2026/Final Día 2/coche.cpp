
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int t, n, m, dM[N], dD[N], dJ[N];
vector<int> adj[N];
queue<int> q;
priority_queue<pair<int, int>> pq;
bitset<N> pushed;

int main(){
  ios::sync_with_stdio(false); cin.tie(nullptr);

  cin >> t;
  while(t--){
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
      adj[i].clear();
      dM[i] = dD[i] = dJ[i] = -1;
      pushed[i] = 0;
    }

    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      x--; y--;

      adj[x].push_back(y);
      adj[y].push_back(x);
    }

    dM[0] = 0; 
    dD[1] = 0;

    q.push(0);    
    while(!q.empty()){
      int x = q.front(); q.pop();
      for(const int &y : adj[x]) {
        if (dM[y] != -1) continue;
        
        dM[y] = dM[x] + 1;
        q.push(y);
      }
    }

    q.push(1);
    while(!q.empty()){
      int x = q.front(); q.pop();
      for(const int &y : adj[x]) {
        if (dD[y] != -1) continue;
        
        dD[y] = dD[x] + 1;
        q.push(y);
      }
    }

    for (int i = 0; i < n; i++) {
      pq.push(make_pair(-max(dM[i], 2 * dD[i]), i));
    }

    while (!pq.empty()) {
      int nwD = -pq.top().first;
      int x = pq.top().second;
      pq.pop();

      if (dJ[x] != -1) continue;
      
      dJ[x] = nwD;
      pushed[x] = 1;

      for (const int &y : adj[x]) {
        if (pushed[y]) continue;
        pushed[y] = 1;
        
        pq.push(make_pair(-(nwD + 1), y));
      }      
    }

    for (int i = 0; i < n; i++) {
      cout << min(2 * dD[i], dJ[i]) << " ";
    }
    cout << "\n";
  }
}
