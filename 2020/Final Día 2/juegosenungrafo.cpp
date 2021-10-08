#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = (int)1e5+7;
int n, m;
vector<int> adj[maxn], deps[maxn];
int subtree_size[maxn];
int component_parent[maxn];
int tree_parent[maxn];

int calc_size(int a) {
  if(subtree_size[a] != 0) {
    return subtree_size[a];
  }
  subtree_size[a] = 1;
  for(int b : deps[a]) {
    subtree_size[a] += calc_size(b);
  }
  return subtree_size[a];
}

int get_parent(int a) {
  if(component_parent[a] == a) return a;
  component_parent[a] = get_parent(component_parent[a]);
  return component_parent[a];
}

int main() {
  int t;
  cin >> t;

  while(t--) {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
      subtree_size[i] = 0;
      component_parent[i] = i;
      tree_parent[i] = i;
      adj[i].clear();
      deps[i].clear();
    }

    for(int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    for(int a = n - 1; a >= 0; a--) {
      for(auto b : adj[a]) if(b > a) { 
        int p = get_parent(b);
        if(p == a) continue;
        deps[a].push_back(p);
        // cout << p << " is dependant upon " << a << endl;
        tree_parent[p] = a;
        component_parent[p] = a;
      }
    }

    for(int a = 0; a < n; a++) {
      calc_size(a);
    } 

    vector<int> ans;

    for(int i = 0; i < n; i++) {
      bool winner = true;
      if(tree_parent[i] != i) {
        int ss = subtree_size[tree_parent[i]];
        int left = n - ss;
        if(left % 2 == 0) {
          winner = false;
        }
      }
      if(winner) {
        ans.push_back(i);
      }
    }

    for(int i = 0; i < (int)ans.size(); i++) {
      if(i > 0) {
        cout << " ";
      }
      cout << ans[i];
    }
    cout << endl;
  } 

  return 0;
}
