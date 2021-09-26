#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

vector <string> A = {"#...........#", ".#.........#.", "..#...#...#..", "...#.#.#.#...", "....#...#...."};
vector <string> B = {"....#...#....", "...#.#.#.#...", "..#...#...#..", ".#.........#.", "#...........#"};
vector <string> C = {"##.........##", "###...#...###", ".###.###.###.", "..#########..", "...###.###..."};
vector <string> D = {"...###.###...", "..#########..", ".###.###.###.", "###...#...###", "##.........##"};


void write(char a, char b, char c){
    for (int i = 0; i < A.size(); ++i){
        for (int j = 0; j < A[0].size(); ++j){
            if (c == 'w' and A[i][j] == '#') cout << b;
            else if (c == 'b' and B[i][j] == '#') cout << b;
            else if (c == 'W' and C[i][j] == '#') cout << b;
            else if (c == 'B' and D[i][j] == '#') cout << b;

            else cout << a;
        }
        cout << '\n';
    }
}

int main (){
    char a, b;
    cin >> a >> b;

    bool first = true;
    char c;
    while (cin >> c) {
        if (first) first = false;
        else cout << "---" << '\n';
        write(a, b, c);
    }
}