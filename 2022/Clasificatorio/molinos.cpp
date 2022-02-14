#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pt = pair<ll,ll>;
#define x first
#define y second

int sign(ll x) {
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

int orientation(pt a, pt b, pt c) {
    ll v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    return sign(v); // +1 -> sentido antihorario
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

struct Fraction {
    ll num, den;
    Fraction(ll num_, ll den_) { num = num_; den = den_; }
};

ll sign(Fraction a) {
    return sign(a.num) * sign(a.den);
}

bool operator<(Fraction a, Fraction b) {
    if (sign(a) == sign(b)) {
        if (sign(a) == 1) 
            return abs(a.num * b.den) < abs(b.num * a.den);
        else if (sign(a) == -1)
            return abs(a.num * b.den) > abs(b.num * a.den);
        else 
            return false;
    }
    return sign(a) < sign(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pt> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    sort(pts.begin(), pts.end(), [](pt a, pt b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    vector<pt> buffer;
    for (int i = 0; i < n; ++i) {
        if (i+1 < n and pts[i].x == pts[i+1].x)
            cout << pts[i].x << ' ' << pts[i].y << '\n';
        else
            buffer.push_back(pts[i]);
    }

    pts = buffer;
    n = pts.size();

    vector<tuple<int,Fraction,pt>> order;
    vector<pt> st;
    for (pt p : pts) {
        while (st.size() >= 2 and !cw(st[st.size()-2], st.back(), p, true)) {
            st.pop_back();
        }
        if (not st.empty()) {
            ll dy = p.y - st.back().y;
            ll dx = p.x - st.back().x;
            if (dy < 0)
                order.push_back({-1, Fraction(dx, -dy), p});
            else if (dy > 0)
                order.push_back({1, Fraction(-dx, dy), p});
            else
                order.push_back({0, Fraction(0, 1), p});
        }
        st.push_back(p);
    }

    sort(order.begin(), order.end());

    for (auto t : order) {
        // cerr << get<0>(t) << " " << (long double)get<1>(t).num << " " << (long double)get<1>(t).num/(long double)get<1>(t).den << endl;
        cout << get<2>(t).x << ' ' << get<2>(t).y << '\n';
    }
} 
