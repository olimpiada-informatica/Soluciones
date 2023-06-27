#include<bits/stdc++.h>

using namespace std;

// Genera el número más pequeño con la propiedad
// deseada que su última cifra es b y al mover b
// delante nos queda el número original multiplicado
// por k.
//
// Este número es único y todos los enteros que
// su última cifra es b y al mover b delante queda
// el original por k son concatenaciones del número
// mínimo, al que llamaremos generador.
string generador(int b, int k) {
    string s = "";
    int v = b;

    do {
        s.push_back(char(v%10 + '0'));
        v = (v%10)*k + v/10;
    } while (v != b);

    reverse(s.begin(), s.end());
    return s;
}

// Nodo para representar nuestro automata
// Cada nodo puede tener un hijo para cada digito
// En cada nodo indicamos la respuesta si terminamos en el
struct node {
    node(int distancia) {
        distanciaMinima = distancia;
    }
    int distanciaMinima;
    unordered_map<char, node*> hijos;
};

// Esta funcion añade un nuevo generador al automata
// Se le pasa el generador ciclado y cuantas iteracions del
// ciclo unitario se han hecho, con esto podemos saber cuantos
// dígitos hay que añadir al inicio para conseguir el generador
// original y con este valor podemos calcular en cada posición 
// cuantos dígitos hay que añadir al final para conseguir una
// concatenación del generador original
//
// Para cada generador ciclado que se introduce se crean (o se usan
// si ya existen) 2n-1 nodos de la forma siguiente:
// root -> a_n_1 -> a_n-1_1 -> ... -> a_0_1 -> a_n_2 -> a_n-1_2 -> ... -> a_1_2
// Al final creamos un ciclo de longitud n conectando a_1_2 -> a_0_1
void addString(node *root, string& numero, int ciclo) {
    node *p = root;
    node *q = nullptr;

    int n = numero.size();
    for (int i = 0; i < 2*n-1; ++i) {
        if (p->hijos.count(numero[i%n]) == 0) {
            p->hijos[numero[i%n]] = new node(3*n);
        }
        if (i == n) q = p;

        int valor = ciclo;
        if (ciclo + i + 1 <= n) valor += n - (ciclo + i + 1);
        else if (ciclo + i + 1 <= 2*n) valor += 2*n - (ciclo + i + 1);
        else valor += 3*n - (ciclo + i + 1);

        p = p->hijos[numero[i%n]];
        p->distanciaMinima = min(p->distanciaMinima, valor);
    }

    p->hijos[numero.back()] = q;
}

// Generamos los diferentes generadores y los ciclamos
// Los añadimos uno a uno al automata para ir creando
// los nodos necesarios o actualizando sus valores
void creaAutomata(node *root) {
    // Inicialmente generamos solamente los generadores
    // para valores de k mayor o igual a 2
    for (int b = 1; b <= 9; ++b) {
        for (int k = 2; k <= 9; ++k) {
            string numero = generador(b, k);
            if (numero[0] == '0') continue;

            for (int ciclo = 0; ciclo < numero.size(); ++ciclo) {
                addString(root, numero, ciclo);

                for (int i = 1; i < numero.size(); ++i) {
                    swap(numero[i-1], numero[i]);
                }
            }
        }
    }
    
    // Una vez creado el automata lo actualizamos con los valores de k=1
    // ya que son un caso especial al ser prefijos de otros generadores
    for (int digito = 1; digito <= 9; ++digito) {
        node *p = root;

        char valorDigito = char('0' + digito);

        while (p->hijos.count(valorDigito)) {
            p = p->hijos[valorDigito];
            p->distanciaMinima = 0;
        }

        p->hijos[valorDigito] = new node(0);
        p->hijos[valorDigito]->hijos[valorDigito] = p->hijos[valorDigito];
    }
}

// Dada una representación decimal solamente tenemos que recorrer el
// automata para ver si tiene solución y encontrar el valor
int getValue(node *root, string& numero) {
    node *p = root;
    for (auto& digito : numero) {
        if (p->hijos.count(digito) == 0) return -1;
        p = p->hijos[digito];
    }

    return p->distanciaMinima;
}

int main() {
    // Creamos el automata, no hace falta leer la entrada
    node *root = new node(0);
    creaAutomata(root);

    int n;
    cin >> n;
    while (n--) {
        string numero;
        cin >> numero;
        int res = getValue(root, numero);
        if (res == -1) cout << "No" << endl;
        else cout << res << endl;
    }
}
