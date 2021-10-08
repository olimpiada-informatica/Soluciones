#include <iostream>

using namespace std;

int main()
{
  int n;
  string matricula, matricula_mas_antigua;
  cin >> n;
  cin >> matricula;
  // En ausencia de mas matriculas la primer matricula es la mas antigua
  // Guardamos las matriculas en el siguiente orden: letras, numeros
  // De esta manera podemos compararlas directamente
  matricula_mas_antigua = matricula.substr(4) + matricula.substr(0, 4);
  while (--n) {
    // Para cada matricula miramos si es mas antigua que la mas antigua que hemos
    // visto hasta ahora, y si lo es pasa a ser la mas antigua
    cin >> matricula;
    matricula = matricula.substr(4) + matricula.substr(0, 4);
    if (matricula.compare(matricula_mas_antigua) < 0) matricula_mas_antigua = matricula;
  }
  // Mostramos la matricula mas antigua intercambiando de nuevo letras y digitos
  cout << matricula_mas_antigua.substr(3) + matricula_mas_antigua.substr(0, 3);
}
