#include <iostream>
using namespace std;

int main() {
  int cajasPequenas, cajasGrandes;
  cin >> cajasPequenas;
  cin >> cajasGrandes;
  
  int totalLatas = cajasPequenas * 6 + cajasGrandes * 15;
  cout << totalLatas << "\n";
  
  return 0;
}
