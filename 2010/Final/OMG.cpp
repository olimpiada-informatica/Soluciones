#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <queue>
 
using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef pair <ll, ll> ii;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;

vi times;
vvi G;

ll solve(int n){
   vector <bool> visited(n+1, false);

   priority_queue <ii> Q;
   Q.push({-times[1], 1});

   while (not Q.empty()){
      ii aux = Q.top(); Q.pop();

      ll d = aux.first;
      int v = aux.second;

      if (v == n) return -d;
      if (visited[v]) continue;

      visited[v] = true;
      for (int i = 0; i < G[v].size(); ++i){
         int u = G[v][i];

         if (visited[u]) continue;
         Q.push({min(d, -times[u]), u});
      }
   }

   return -1;
}

int main() {
   int n; 
   cin >> n;

   times = vi(n+1);
   G = vvi(n+1);
   
   for (int i = 1; i < n; ++i){
      string s;
      cin >> s;
      getline(cin, s);

      stringstream ss(s);
      ss >> times[i];

      int x;
      while (ss >> x) G[i].push_back(x);
   }
   
   cout << solve(n) << endl;
}