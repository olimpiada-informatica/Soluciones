#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
typedef long long int ll;
typedef pair <int, int> ii;

void read(vector <ii>& V){
    for (int i = 0; i < V.size(); ++i){
        int h1, m1, h2, m2;
        char c;

        cin >> h1 >> c >> m1 >> c >> c >> h2 >> c >> m2;
        int time1 = h1*60 + m1;
        int time2 = h2*60 + m2;

        if (time2 < time1) time2 += 24*60;
        V[i] = {time1, time2};
    }
}


int main (){
    int n, m;
    while (cin >> n >> m){
        vector <ii> A(n), B(m);

        read(A);    
        read(B);

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int total = 0;
        for (int time = 0; time < 60*24; ++time){
            bool found = false;

            for (int i = 0; i < n and not found; ++i){
                if (A[i].first <= time and A[i].second > time) found = true;
                if (A[i].first <= time+24*60 and A[i].second > time+24*60) found = true;
            }

            if (not found) continue;
            else found = false;

            for (int i = 0; i < m and not found; ++i){
                if (B[i].first <= time and B[i].second > time) found = true;
                if (B[i].first <= time+24*60 and B[i].second > time+24*60) found = true;
            }

            if (found) ++total;      
        }

        cout << total << '\n';
    }
}