#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
 
using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <pair <int, int> > vii;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef vector <vvvi> vvvvi;
 
vi V;
ll m;

bool possible (ll d){
   ll used = 0;

   ll dist = 0;
   for (int i = 0; i < V.size(); ++i){
      if (V[i] > 2*d) return false;

      if (dist + V[i] > d){
         ++used;
         dist = -d;
      }
      dist += V[i];
   }

   if (dist > 0) ++used;
   return used <= m;
}

int main() {
   ll n;
   while (cin >> n >> m){
      V = vi(n);
      for (int i = 0; i < n; ++i) cin >> V[i];

      ll left = 0, right = 0;
      for (int i = 0; i < n; ++i) right += V[i];


      while (left + 1 < right){
         ll middle = (left + right)/2;

         if (possible(middle)) right = middle;
         else left = middle + 1;
      }

      if (not possible(left)) ++left;
      cout << left << endl;
   }
}