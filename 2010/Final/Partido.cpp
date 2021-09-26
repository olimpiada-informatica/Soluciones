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


int main() {
   string a, b;
   cin >> a >> b;

   int pa = 0, pb = 0;
   int x;

   while (cin >> x){
      if (x == 1) ++pa;
      if (x == 2) ++pb;
      if (x == -1){
         cout << a << " " << pa << "-" << pb << " " << b << endl;
         break;
      }
   }
}