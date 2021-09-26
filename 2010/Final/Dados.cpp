#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef vector <int> vi;
typedef long long int ll;

vi possibilities1 = {0, 6, 6, 6, 6, 6, 6};
vi possibilities2 = {0, 0, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1};


int evalua(int caso, string signo, int numero){
    if (caso == 1){
        if (signo == "="){
            if (numero > 6 or numero < 0) return 0;
            else return possibilities1[numero];
        }
        if (signo == ">"){
            int value = 0;
            for (int i = max(1, numero + 1); i < possibilities1.size(); ++i) value += possibilities1[i];
            return value;
        }
        if (signo == ">="){
            int value = 0;
            for (int i = max(1, numero); i < possibilities1.size(); ++i) value += possibilities1[i];
            return value;
        }
        if (signo == "<"){
            int value = 0;
            for (int i = min(numero - 1, 6); i > 0; --i) value += possibilities1[i];
            return value;
        }
        if (signo == "<="){
            int value = 0;
            for (int i = min(numero, 6); i > 0; --i) value += possibilities1[i];
            return value;
        }
    }
    else {
        if (signo == "="){
            if (numero > 12 or numero < 0) return 0;
            else return possibilities2[numero];
        }
        if (signo == ">"){
            int value = 0;
            for (int i = max(1, numero + 1); i < possibilities2.size(); ++i) value += possibilities2[i];
            return value;
        }
        if (signo == ">="){
            int value = 0;
            for (int i = max(1, numero); i < possibilities2.size(); ++i) value += possibilities2[i];
            return value;
        }
        if (signo == "<"){
            int value = 0;
            for (int i = min(numero - 1, 12); i > 0; --i) value += possibilities2[i];
            return value;
        }
        if (signo == "<="){
            int value = 0;
            for (int i = min(numero, 12); i > 0; --i) value += possibilities2[i];
            return value;
        }
    }
}

int main (){
    int caso1, numero1, caso2, numero2;
    string signo1, signo2;

    while (cin >> caso1 >> signo1 >> numero1 >> caso2 >> signo2 >> numero2){
        int prob1 = evalua(caso1, signo1, numero1);
        int prob2 = evalua(caso2, signo2, numero2);

        if (prob1 == prob2) cout << '=' << endl;
        if (prob1 > prob2) cout << 'A' << endl;
        if (prob1 < prob2) cout << 'B' << endl;

        string basura;
        cin >> basura;
    }
}