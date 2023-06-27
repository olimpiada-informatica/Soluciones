#include<bits/stdc++.h>

using namespace std;

bool solve1(int n, int a, int x) {
    return n >= 0 && n % x == 0 && n/x <= a;
}

bool solve2(int n, int a, int b, int x, int y) {
    if (n < 0) return false;
    //Opcion que maximice los del primer tipo
    //O bien usa >= a-y del primer tipo
    for (int i=max(0, a-y); i <= a; ++i) {
        if(solve1(n-i*x, b, y)) return true;
    }
    //O bien < x del segundo tipo
    for (int j=0; j <= min(x-1, b); ++j) {
        if(solve1(n-j*y, a, x)) return true;
    }
    return false;
}

bool solve235(int n, int a, int b, int c) {
    //Maximiza el número del tercer tipo
    //O bien usa todas del tercer tipo, o bien no usa de uno de los 
    //2 primeros tipos
    return solve2(n-5*c, a, b, 2, 3) || solve2(n, a, c, 2, 5) || solve2(n, b, c, 3, 5);
}

bool solve456(int n, int a, int b, int c) {
    if (b == 0) {
        if (n%2) return false;
        return solve2(n/2, a, c, 2, 3);
    }
    //La paridad del segundo tipo viene dada por la paridad de n
    if (n%2) return solve235((n-5)/2, a, c, (b-1)/2);
    return solve235(n/2, a, c, b/2);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
       int n, a, b, c;
       cin >> n >> a >> b >> c;
       cout << (solve456(n, a, b, c) ? "SI" : "NO") << endl;
    }
}