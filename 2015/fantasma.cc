#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<string> formas(5);
	vector<string> colores(5);
	map<string, int> formasIdx;
	map<string, int> coloresIdx;
	for (int i = 0; i < 5; i++){
		cin >> formas[i] >> colores[i];
		formasIdx[formas[i]] = i;
		coloresIdx[colores[i]] = i;
	}
	string f1, c1, f2, c2;
	while (cin >> f1 >> c1 >> f2 >> c2){
		int forma1 = formasIdx[f1], color1 = coloresIdx[c1];
		int forma2 = formasIdx[f2], color2 = coloresIdx[c2];
		if (forma1 != forma2 and color1 != color2 and forma1 != color2 and forma2 != color1 and (forma1 != color1 or forma2 != color2)){
			if (forma1 == color1)
				cout << formas[forma1] << ' ' << colores[color1] << '\n';
			else if (forma2 == color2)
				cout << formas[forma2] << ' ' << colores[color2] << '\n';
			else{
				int indiceRestante = 10-forma1-color1-forma2-color2;
				cout << formas[indiceRestante] << ' ' << colores[indiceRestante] << '\n';
			}
		}
		else{
			cout << "Expansion\n";
		}
	}
}