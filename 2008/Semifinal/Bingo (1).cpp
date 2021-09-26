#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <set>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

int main (){
    int k;
    cin >> k;

    vvvi Bingo(k+1, vvi(3, vi(5)));

    for (int i = 1; i <= k; ++i){
        for (int j = 0; j < 3; ++j){
            for (int h = 0; h < 5; ++h) cin >> Bingo[i][j][h];
        }
    }

    int q;
    cin >> q;

    vvi queries(q);

    for (int w = 0; w <
     q; ++w){
        int p;
        cin >> p;

        queries[w] = vi(p);
        for (int i = 0; i < p; ++i) cin >> queries[w][i];
    }

    vi appear(100);
    for (int i = 0; i < 99; ++i){
        int x;
        cin >> x;

        appear[x] = i;
    }

    vi times(k+1, 100);
    vi times2(k+1, 0);

    for (int i = 1; i <= k; ++i){
        int minimum = 100;
        for (int j = 0; j < 3; ++j){
            int row = 0;

            for (int h = 0; h < 5; ++h) row = max(row, appear[Bingo[i][j][h]]);

            times2[i] = max(times2[i], row);
            minimum = min(minimum, row);
        }

        times[i] = minimum;
    }

    for (int w = 0; w < q; ++w){
        int minimum1 = 100, tim1 = 0, index1 = 0;
        int minimum2 = 100, tim2 = 0, index2 = 0;

        for (int r = 0; r < queries[w].size(); ++r){
            int p = queries[w][r];


            if (minimum1 == times[p]) ++tim1;
            if (minimum2 == times2[p]) ++tim2;

            if (minimum1 > times[p]){
                minimum1 = times[p];
                tim1 = 1;
                index1 = p;
            }

            if (minimum2 > times2[p]){
                minimum2 = times2[p];
                tim2 = 1;
                index2 = p;
            }
        }

        if (tim1 == 1) cout << index1;
        else cout << 0;

        cout << ' ';

        if (tim2 == 1) cout << index2;
        else cout << 0;
        cout << '\n';
    }
}