#include <bits/stdc++.h>

using namespace std;

int diasMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct fecha{
	int d, m, a;
	fecha(){
		d = m = a = 0;
	}
	fecha (int D, int M, int A){
		d = D;
		m = M;
		a = A;
	}
	fecha prev(){
		int D = d, M = m, A = a;
		D--;
		if (D == 0){
			M--;
			if (M == 0){
				M = 12;
				A--;
			}
			D = diasMes[M];
		}
		return fecha(D, M, A);
	}
	fecha next(){
		int D = d, M = m, A = a;
		D++;
		if (D > diasMes[M]){
			M++;
			D = 1;
			if (M == 13){
				A++;
				M = 1;
			}
		}
		return fecha(D, M, A);
	}
	bool read(){
		d = m = a = 0;
		string s;
		if (cin >> s){
			int idx = 0;
			while (s[idx] != '-'){
				d = 10*d + s[idx]-'0';
				idx++;
			}
			idx++;
			while (s[idx] != '-'){
				m = 10*m + s[idx]-'0';
				idx++;
			}
			idx++;
			a = 1000*(s[idx]-'0') + 100*(s[idx+1]-'0') + 10*(s[idx+2]-'0') + (s[idx+3]-'0');
			return true;
		}
		return false;
	}
	int id(){
		return 31*12*(a-2014)+31*(m-1)+d-1;
	}
};

int main(){
	map<int, int> diaSem;
	fecha actFecha = fecha(1, 1, 2014);
	int actDiaSem = 2;
	while (actFecha.a < 2016){
		diaSem[actFecha.id()] = actDiaSem;
		actFecha = actFecha.next();
		actDiaSem = (actDiaSem+1)%7;
	}
	int n;
	cin >> n;
	map<int, bool> fiesta;
	while(n--){
		fecha F;
		F.read();
		fiesta[F.id()] = true;
	}
	fecha F;
	while (F.read()){
		int dSem = diaSem[F.id()];
		bool ans = false;
		if ((28 <= F.d and F.m == 12) or (3 >= F.d and F.m == 1)){
			ans = false;
		}
		else if (dSem == 2 or dSem == 3 or dSem == 5 or dSem == 6){
			ans = true;
		}
		else if (fiesta[F.id()] and (F.d != 23 or F.m != 12)){
			ans = true;
		}
		else if (dSem == 0 and fiesta[F.prev().id()]){
			ans = true;
		}
		else if (dSem == 1){
			fecha prev = F.prev();
			fecha prev2 = prev.prev();
			ans = not ((fiesta[prev.id()] and (prev.d != 23 or prev.m != 12)) or fiesta[prev2.id()]);
		}
		cout << (ans ? "ABIERTOS\n" : "CERRADOS\n");
	}

}