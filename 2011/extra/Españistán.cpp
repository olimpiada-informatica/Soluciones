#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stdlib.h>
#include <time.h> 

using namespace std;
typedef long long int ll;
typedef pair <ll, ll> ii;
typedef vector <ll> vi;
typedef vector <vi> vvi;

struct Node {
    ll key, pr;
    ll childs, sum, copies;
    Node *l, *r;
};

typedef Node* Treap;

ll sum_amount(Treap T){
    if (not T) return 0;
    return T -> sum;
}

ll sum_childs(Treap T){
    if (not T) return 0;
    return T -> childs;
}

void update(Treap T){
    T -> sum = (T -> key) * T -> copies + sum_amount(T -> r) + sum_amount(T -> l);
    T -> childs = T -> copies + sum_childs(T -> r) + sum_childs(T -> l);
}

void split (Treap T, ll k, Treap& L, Treap& R){
    if (not T) L = R = nullptr;

    else if (k < T -> key) {
        split(T -> l, k, L, T -> l);
        R = T;
        update(R);
    }

    else {
        split(T -> r, k, T -> r, R);
        L = T;
        update(L);
    }  
}


void insert (Treap& T, Treap a){
    if (not T) T = a;

    else if (a -> pr > T -> pr){
        split(T, a -> key, a -> l, a -> r);
        T = a;
    }

    else {
        if (a -> key < T -> key) insert(T -> l, a);
        else insert(T -> r, a);
    }

    update(T);
}

bool add_find(Treap& T, int k){
    if (not T) return false;

    bool ans = false;

    if (T -> key == k){
        ++T -> copies;
        ans = true;
    }

    else if (T -> key > k) ans = add_find(T -> l, k);
    else ans = add_find(T -> r, k);

    update(T);
    return ans;
}

bool quit_find(Treap& T, int k){
    if (not T) return true;

    bool ans = false;

    if (T -> key == k){
        if (T -> copies > 1) {
            --T -> copies;
            ans = true;
        }
    }

    else if (T -> key > k) ans = quit_find(T -> l, k);
    else ans = quit_find(T -> r, k);

    update(T);
    return ans;
}

void merge (Treap& T, Treap L, Treap R) { // L < R (all values)
    if (not L) T = R;
    else if (not R) T = L;

    else if (L -> pr > R -> pr) {
        merge (L -> r, L -> r, R);
        T = L;
        update(T);

    }

    else {
        merge (R -> l, L, R -> l);
        T = R;
        update(T);
    }
}


void erase (Treap& T, ll k) {
    if (T -> key == k) merge (T, T -> l, T -> r);
    
    else {
        if (k < T -> key) erase (T -> l, k);
        else erase (T -> r, k);
        update(T);
    }
}



ll sum_smaller(Treap T, ll k){
    if (not T) return 0;

    if (T -> key <= k) return T -> sum - sum_amount(T -> r) + sum_smaller(T -> r, k);
    return sum_smaller(T -> l, k);
}

ll childs_smaller(Treap T, ll k){
    if (not T) return 0;

    if (T -> key <= k) return T -> childs - sum_childs(T -> r) + childs_smaller(T -> r, k);
    return childs_smaller(T -> l, k);
}


int main() {
    srand (time(NULL));

    ll n, s, t;
    cin >> n >> s >> t;

    vi V(n+1);
    for (int i = 1; i <= n; ++i) cin >> V[i];

    vi sums = V;
    for (int i = 1; i <= n; ++i) sums[i] += sums[i-1];

    ll left = 1, fuera = 1e18, mover = 1e18;
    
    Treap T = nullptr;
    for (int i = 1; i < s; ++i){
        Treap aux = new Node {V[i], rand(), 1, V[i], 1, nullptr, nullptr};
        if (not add_find(T, V[i])) insert(T, aux);
    }

    for (int i = s; i <= n; ++i) {
        Treap aux = new Node {V[i], rand(), 1, V[i], 1, nullptr, nullptr};
        if (not add_find(T, V[i])) insert(T, aux);
        
        ll SUM = sums[i] - sums[i-s];
        ll h = SUM/s;

        ll out = SUM - s * h;
        if (out <= fuera){
            ll move = h * childs_smaller(T, h) - sum_smaller(T, h);
            
            if (out < fuera or move < mover){
                left = i - s + 1;
                fuera = out;
                mover = move;
            }
        }
        
        if (not quit_find(T, V[i-s+1])) erase(T, V[i-s+1]);
    }

    cout << left << " " << left + s - 1 << endl;
    cout << fuera << " " << mover << endl;
}   