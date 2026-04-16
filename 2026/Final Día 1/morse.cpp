// Solución óptima O(N): Aprovecha el patrón del Morse donde los puntos de un dígito 'd' son min(d, 10 - d).
// Como cada dígito se representa siempre con una combinación de exactamente cinco símbolos, 
// el total de rayas se obtiene restando los puntos calculados al total de símbolos (5 * longitud).


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int points = 0;

        for (char c : s) {
            int d = c - '0';
            points += min(d, 10 - d);
        }
        
        int dashes = 5 * s.length() - points;

        cout << points << " " << dashes << "\n";
    }

    return 0;
}
