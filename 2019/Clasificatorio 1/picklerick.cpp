#include <bits/stdc++.h>

using namespace std;

const int INF = 1e8;

vector <vector <int> >dist;
priority_queue <pair <int, pair <int,int> > >q;

void move2(int x, int y, int d) {
  if (x < 0 || x >= 1030 || y < 0 || y >= 1030 || dist[x][y] <= d) return;
  dist[x][y] = d;
  q.push({-d, {x, y}});
}

void move(int curx, int cury, int d1, int d2, int d) {
  move2(curx+d1, cury+d2, d);
  move2(curx+d1, cury-d2, d);
  move2(curx-d1, cury+d2, d);
  move2(curx-d1, cury-d2, d);
  move2(curx+d2, cury+d1, d);
  move2(curx+d2, cury-d1, d);
  move2(curx-d2, cury+d1, d);
  move2(curx-d2, cury-d1, d);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  dist = vector <vector <int> >(1030, vector <int>(1030, INF));
  q.push({0, {15, 15}});
  dist[15][15] = 0;
  while (!q.empty()) {
    pair <int, pair <int,int> >p = q.top();
    q.pop();
    p.first = -p.first;

    move(p.second.first, p.second.second, 0, 2, p.first+4);
    move(p.second.first, p.second.second, 0, 3, p.first+2);
    move(p.second.first, p.second.second, 1, 3, p.first+3);
    move(p.second.first, p.second.second, 0, 1, p.first+3);
    move(p.second.first, p.second.second, 2, 3, p.first+4);

  }
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x < 1000 && y < 1000) cout << dist[x+15][y+15] << '\n';
    else {
      int ans = 2e9+50;
      for (int i = x%3; i < 30; i += 3) {
        for (int j = y%3; j < 30; j += 3) {
          ans = min(ans, dist[i][j]+2*((x+y+30-i-j)/3));
        }
      }
      cout << ans << '\n';
    }
  }
}
