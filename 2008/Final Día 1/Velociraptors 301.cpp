#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct pt {
    int x, y;
};

bool comp(pt a, pt b){
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

int main () {
    int n, m, k;
    while (cin >> n >> m >> k){
        vector <pt> V(m);
        for (int i = 0; i < m; ++i) cin >> V[i].x >> V[i].y;

        sort(V.begin(), V.end(), comp);

        pt left = V[0];
        vector <pt> good = {left};

        for (int i = 1; i < m; ++i){
            int x = V[i].x - left.x;
            int y = left.y + x;

            if (y >= V[i].y) {
                left = V[i];
                good.push_back(V[i]);
            }
        }

        V = good;
        pt right = V.back();
        good = {right};

        for (int i = V.size()-2; i >= 0; --i){
            int x = right.x - V[i].x;
            int y = right.y + x;

            if (y >= V[i].y) {
                good.push_back(V[i]);
                right = V[i];
            }
        }

        V = good;
        reverse(V.begin(), V.end());

        vector <pt> intersect = {{0, V[0].y + V[0].x}};

        for (int i = 1; i < V.size(); ++i){
            int n1 = V[i-1].y - V[i-1].x;
            int n2 = V[i].y + V[i].x;

            int x = (n2 - n1)/2;
            intersect.push_back({x, V[i-1].y + x - V[i-1].x});
        }

        intersect.push_back({2*n-2, V.back().y + 2*n-2 - V.back().x});

        int best = 0;
        for (int i = 0; i < intersect.size(); ++i){
            pt aux = intersect[i];
            int y = abs(aux.x - k);
            
            if (y < aux.y) best = max(best, aux.y); 
        }

        cout << best << endl;
    }
}