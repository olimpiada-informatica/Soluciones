#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int s = 0;
        int odd = 0;
        for(int i=0; i < n; ++i) {
            int a;
            cin >> a;
            s += a;
            if(a%2) odd++;
        }
        if(odd == 0) {
            cout << 1 << endl;
        }
        else {
            int ans = s;
            for(int i=1; i*i <= s; i++) {
                if(s%i ==0) {
                    int d1 = i;
                    int d2 = s/i;
                    
                    if((s/d1) % 2 && d1 >= odd && (d1-odd) % 2 == 0) {
                        ans = d1;
                        break;
                    }
                    else if((s/d2) % 2 && d2 >= odd && (d2-odd) % 2 == 0) {
                        ans = d2;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
