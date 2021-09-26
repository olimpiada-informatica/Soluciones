#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> ii;
typedef vector <int> vi;

int x, y;
vector <vector <char> > T;
vector <vi> P;

vector <int> X = {1,1,-1,-1,2,2,-2,-2};
vector <int> Y = {2,-2,2,-2,1,-1,1,-1};

int winx, winy;
char winpiece;

void print (){
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j) {
            if (i == x and j == y) cout << "*";
            else cout << T[i][j];
        }
        cout << endl;
    }
    cout << "-------------------" << endl;
}

bool safe (int a, int b){
    for (int i = -1; i <= 1; ++i){
        for (int j = -1; j <= 1; ++j){
            if (a + i >= 0 and a + i < 8 and b + j >= 0 and b + j < 8) {
                if (T[a+i][b+j] == '0') return false;
            }
        }
    }

    for (int i = 1; i + a < 8 and i + b < 8; ++i){
        int c = T[a+i][b+i] - '0';
        if (c == 1 or c == 2) return false;
        if (c >= 0) i = 100; 
    }
    for (int i = -1; i + a >= 0 and i + b >= 0; --i){
        int c = T[a+i][b+i] - '0';
        if (c == 1 or c == 2) return false;
        if (c >= 0) i = -100;
    }
    for (int i = 1; a - i >= 0 and i + b < 8; ++i){
        int c = T[a-i][b+i] - '0';
        if (c == 1 or c == 2) return false;
        if (c >= 0) i = 100; 
    }
    for (int i = 1; i + a < 8 and b - i >= 0; ++i){
        int c = T[a+i][b-i] - '0';
        if (c == 1 or c == 2) return false;
        if (c >= 0) i = 100; 
    }


    for (int i = 1; i + a < 8; ++i){
        int c = T[a+i][b] - '0';
        if (c == 1 or c == 4) return false;
        if (c >= 0) i = 100; 
    }
    for (int i = -1; i + a >= 0; --i){
        int c = T[a+i][b] - '0';
        if (c == 1 or c == 4) return false;
        if (c >= 0) i = -100; 
    }
    for (int i = 1; i + b < 8; ++i){
        int c = T[a][b+i] - '0';
        if (c == 1 or c == 4) return false;
        if (c >= 0) i = 100; 
    }
    for (int i = -1; i + b >= 0; --i){
        int c = T[a][b+i] - '0';
        if (c == 1 or c == 4) return false;
        if (c >= 0) i = -100; 
    }

    for (int i = 0; i < 8; ++i){
        int newx = a + X[i];
        int newy = b + Y[i];

        if (newx >= 0 and newx < 8 and newy >= 0 and newy < 8 and T[newx][newy] == '3') return false;
    }

    return true;
}

bool checkmate (){
    for (int i = -1; i <= 1; ++i){
        for (int j = -1; j <= 1; ++j){
            if (x + i >= 0 and x + i < 8 and y + j >= 0 and y + j < 8) {
                if (safe(x+i, y+j)) {
                    return false;
                }
            }
        }
    }

    return true;
}

int king (int a, int b) {

    int count = 0;

    for (int i = -1; i <= 1; ++i){
        for (int j = -1; j <= 1; ++j){
            if (a + i >= 0 and a + i < 8 and b + j >= 0 and b + j < 8) {
                if (abs(a+i-x) > 1 or abs(b+j-y) > 1){
                    if (T[a+i][b+j] == '.') {
                        T[a][b] = '.';
                        T[a+i][b+j] = '0';

                        if (checkmate()){
                            ++count;
                            winx = a+i;
                            winy = b+j;
                            winpiece = 'R';
                        }

                        T[a][b] = '0';
                        T[a+i][b+j] = '.';
                    }
                }
            }
        }
    }

    return count;
}

int queen (int a, int b) {
    int count = 0;

    for (int i = 1; i + a < 8 and i + b < 8; ++i){
        char c = T[a+i][b+i];
        if (c != '.') i = 100;
        else{
            T[a][b] = '.';
            T[a+i][b+i] = '1';

            if (checkmate()){
                ++count;
                winx = a+i;
                winy = b+i;
                winpiece = 'D';
            }

            T[a][b] = '1';
            T[a+i][b+i] = '.';
        }
    }


    for (int i = -1; i + a >= 0 and i + b >= 0; --i){
        char c = T[a+i][b+i];
        if (c != '.') i = -100;
        else{
            T[a][b] = '.';
            T[a+i][b+i] = '1';

            if (checkmate()){
                ++count;
                winx = a+i;
                winy = b+i;
                winpiece = 'D';
            }

            T[a][b] = '1';
            T[a+i][b+i] = '.';
        }
    }


    for (int i = 1; a - i >= 0 and i + b < 8; ++i){
        char c = T[a-i][b+i];
        if (c != '.') i = 100;
        else{
            T[a][b] = '.';
            T[a-i][b+i] = '1';

            if (checkmate()){
                ++count;
                winx = a-i;
                winy = b+i;
                winpiece = 'D';
            }

            T[a][b] = '1';
            T[a-i][b+i] = '.';
        }
    }


    for (int i = 1; i + a < 8 and b - i >= 0; ++i){
        char c = T[a+i][b-i];
        if (c != '.') i = 100;
        else{
            T[a][b] = '.';
            T[a+i][b-i] = '1';

            if (checkmate()){
                ++count;
                winx = a+i;
                winy = b-i;
                winpiece = 'D';
            }

            T[a][b] = '1';
            T[a+i][b-i] = '.';
        } 
    }


    for (int i = 1; i + a < 8; ++i){
        char c = T[a+i][b];
        if (c != '.') i = 100;
        else{
            T[a][b] = '.';
            T[a+i][b] = '1';

            if (checkmate()){
                ++count;
                winx = a+i;
                winy = b;
                winpiece = 'D';
            }

            T[a][b] = '1';
            T[a+i][b] = '.';
        }
    }
    for (int i = -1; i + a >= 0; --i){
        char c = T[a+i][b];
        if (c != '.') i = -100;
        else{
            T[a][b] = '.';
            T[a+i][b] = '1';

            if (checkmate()){
                ++count;
                winx = a+i;
                winy = b;
                winpiece = 'D';
            }

            T[a][b] = '1';
            T[a+i][b] = '.';
        }
    }
    for (int i = 1; i + b < 8; ++i){
        char c = T[a][b+i];
        if (c != '.') i = 100;
        else{
            T[a][b] = '.';
            T[a][b+i] = '1';

            if (checkmate()){
                ++count;
                winx = a;
                winy = b+i;
                winpiece = 'D';
            }

            T[a][b] = '1';
            T[a][b+i] = '.';
        }
    }
    for (int i = -1; i + b >= 0; --i){
        char c = T[a][b+i];
        if (c != '.') i = -100;
        else{
            T[a][b] = '.';
            T[a][b+i] = '1';

            if (checkmate()){
                ++count;
                winx = a;
                winy = b+i;
                winpiece = 'D';
            }

            T[a][b] = '1';
            T[a][b+i] = '.';
        }
    }

    return count;
}

int bishop (int a, int b) {
    int count = 0;


    for (int i = 1; i + a < 8 and i + b < 8; ++i){
        char c = T[a+i][b+i];
        if (c != '.') i = 100;
        else{
            T[a][b] = '.';
            T[a+i][b+i] = '2';

            if (checkmate()){
                ++count;
                winx = a+i;
                winy = b+i;
                winpiece = 'A';
            }

            T[a][b] = '2';
            T[a+i][b+i] = '.';
        }
    }


    for (int i = -1; i + a >= 0 and i + b >= 0; --i){
        char c = T[a+i][b+i];
        if (c != '.') i = -100;
        else{
            T[a][b] = '.';
            T[a+i][b+i] = '2';

            if (checkmate()){
                ++count;
                winx = a+i;
                winy = b+i;
                winpiece = 'A';
            }

            T[a][b] = '2';
            T[a+i][b+i] = '.';
        }
    }


    for (int i = 1; a - i >= 0 and i + b < 8; ++i){
        char c = T[a-i][b+i];
        if (c != '.') i = 100;
        else{
            T[a][b] = '.';
            T[a-i][b+i] = '2';

            if (checkmate()){
                ++count;
                winx = a-i;
                winy = b+i;
                winpiece = 'A';
            }

            T[a][b] = '2';
            T[a-i][b+i] = '.';
        }
    }


    for (int i = 1; i + a < 8 and b - i >= 0; ++i){
        char c = T[a+i][b-i];
        if (c != '.') i = 100;
        else{
            T[a][b] = '.';
            T[a+i][b-i] = '2';

            if (checkmate()){
                ++count;
                winx = a+i;
                winy = b-i;
                winpiece = 'A';
            }

            T[a][b] = '2';
            T[a+i][b-i] = '.';
        } 
    }

    return count;
}

int knight (int a, int b) {
    int count = 0;

    for (int i = 0; i < 8; ++i){
        int newx = a + X[i];
        int newy = b + Y[i];

        if (newx >= 0 and newx < 8 and newy >= 0 and newy < 8 and T[newx][newy] == '.'){
            T[a][b] = '.';
            T[newx][newy] = '3';

            if (checkmate()){
                ++count;
                winx = newx;
                winy = newy;
                winpiece = 'C';
            }

            T[a][b] = '3';
            T[newx][newy] = '.';
        }
    }

    return count;
}

int rook (int a, int b) {
    int count = 0;

    for (int i = 1; i + a < 8; ++i){
        char c = T[a+i][b];
        if (c != '.') i = 100;
        else{
            T[a][b] = '.';
            T[a+i][b] = '4';

            if (checkmate()){
                ++count;
                winx = a+i;
                winy = b;
                winpiece = 'T';
            }

            T[a][b] = '4';
            T[a+i][b] = '.';
        }
    }

    for (int i = -1; i + a >= 0; --i){
        char c = T[a+i][b];
        if (c != '.') i = -100;
        else{
            T[a][b] = '.';
            T[a+i][b] = '4';

            if (checkmate()){
                ++count;
                winx = a+i;
                winy = b;
                winpiece = 'T';
            }

            T[a][b] = '4';
            T[a+i][b] = '.';
        }
    }


    for (int i = 1; i + b < 8; ++i){
        char c = T[a][b+i];
        if (c != '.') i = 100;
        else{
            T[a][b] = '.';
            T[a][b+i] = '4';

            if (checkmate()){
                ++count;
                winx = a;
                winy = b+i;
                winpiece = 'T';
            }

            T[a][b] = '4';
            T[a][b+i] = '.';
        }
    }

    for (int i = -1; i + b >= 0; --i){
        char c = T[a][b+i];
        if (c != '.') i = -100;
        else{
            T[a][b] = '.';
            T[a][b+i] = '4';

            if (checkmate()){
                ++count;
                winx = a;
                winy = b+i;
                winpiece = 'T';
            }

            T[a][b] = '4';
            T[a][b+i] = '.';
        }
    }

    return count;
}

void solve () {
    int cheks = 0;

    for (int i = 0; i < P.size(); ++i){
        if (P[i][0] == 0) cheks += king(P[i][1], P[i][2]);
        if (P[i][0] == 1) cheks += queen(P[i][1], P[i][2]);
        if (P[i][0] == 2) cheks += bishop(P[i][1], P[i][2]);
        if (P[i][0] == 3) cheks += knight(P[i][1], P[i][2]);
        if (P[i][0] == 4) cheks += rook(P[i][1], P[i][2]);
    }

    if (cheks == 0) cout << "NO" << endl;
    else if (cheks > 1) cout << ">1" << endl;
    else cout << winpiece << char('a'+winy) << winx+1 << endl;
}

int main(){
    string s;
    map <char, int> M;
    M['R'] = 0;
    M['D'] = 1;
    M['A'] = 2;
    M['C'] = 3;
    M['T'] = 4;

    while (cin >> s){
        y = s[1] - 'a';
        x = s[2] - '1';

        int n;
        cin >> n;

        P = vector <vi> (n);
        T = vector <vector <char> > (8, vector <char> (8, '.'));

        for (int i = 0; i < n; ++i){
            string t; cin >> t;

            int piece = M[t[0]];
            int a = t[1] - 'a';
            int b = t[2] - '1';
            T[b][a] = '0' + piece;

            P[i] = {piece, b, a};
        }

        solve();
    }
}