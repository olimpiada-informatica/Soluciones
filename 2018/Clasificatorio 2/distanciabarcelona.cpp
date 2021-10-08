#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
typedef pair<pi,int> ppi;

int dist(pi a, pi b) {
    int res = abs(a.first-b.first)+abs(a.second-b.second);
    int distx = abs(b.first-b.second)+abs(a.first-a.second);
    return min(res,distx);
}

bool xec(pi a) {
    return (a.first%10 == 0) and (a.second%10 == 0);
}

pi addx(pi a, int i) {
    return pi(a.first +i,  a.second);
}

pi addy(pi a, int i) {
    return pi(a.first,i +  a.second);
}

void putoDean(pi a) {
	assert(abs(a.first) <= 10000000);
	assert(abs(a.second) <= 10000000);
	assert(a.first%10 == 0 or a.second%10 == 0);
}

int main() {
    int x,y;
    while (cin >> x >> y) {
        pi s(x,y);
	putoDean(s);
        int q;
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b;
            pi f(a,b);
	    putoDean(f);
            int res = 1e9;
            vector<ppi> Vx;
            vector<ppi> Vy;
            for (int i = -10; i <= 10; ++i) {
                if (xec(addx(f,i))) Vx.push_back(ppi(addx(f,i),abs(i)));
                if (xec(addy(f,i))) Vx.push_back(ppi(addy(f,i),abs(i)));
                if (xec(addx(s,i))) Vy.push_back(ppi(addx(s,i),abs(i)));
                if (xec(addy(s,i))) Vy.push_back(ppi(addy(s,i),abs(i)));
            }
            for (int i = 0; i < (int)Vx.size(); ++i)
                for (int j = 0; j < (int)Vy.size(); ++j)
                    res = min(res,dist(Vx[i].first,Vy[j].first) + Vx[i].second + Vy[j].second);
            cout << res;
		if (q) cout << ' ';
            else cout << endl;
        }
   }
}
