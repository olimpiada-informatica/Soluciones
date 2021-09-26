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
    ll sum;
    ll childs;
    Node *l, *r;
};

typedef Node* Treap;

const ll mod = 1e9;

void print (Treap T){
    if (not T) return;
    cout << T -> key << " " << T -> pr << "  " << T -> sum << " and childs " << T -> childs << endl;
    
    cout << "left is " << endl;
    print (T -> l);

    cout << "right is " << endl;
    print(T -> r);
}

void split (Treap T, ll k, Treap& L, Treap& R){
    if (not T) L = R = nullptr;

    else if (k < T -> key) {
        split(T -> l, k, L, T -> l);

        T -> sum = T -> key;
        if (T -> l) T -> sum += T -> l -> sum;
        if (T -> r) T -> sum += T -> r -> sum;

        T -> childs = 1;
        if (T -> l) T -> childs += T -> l -> childs;
        if (T -> r) T -> childs += T -> r -> childs;

        R = T;
    }

    else {
        split(T -> r, k, T -> r, R);

        T -> sum = T -> key;
        if (T -> l) T -> sum += T -> l -> sum;
        if (T -> r) T -> sum += T -> r -> sum;

        T -> childs = 1;
        if (T -> l) T -> childs += T -> l -> childs;
        if (T -> r) T -> childs += T -> r -> childs;

        L = T;
    }  
}


void insert (Treap& T, Treap a){
    if (not T) T = a;

    else if (a -> pr > T -> pr){
        split(T, a -> key, a -> l, a -> r);
            
        T = a;

        T -> sum = T -> key;
        if (T -> l) T -> sum += T -> l -> sum;
        if (T -> r) T -> sum += T -> r -> sum;

        T -> childs = 1;
        if (T -> l) T -> childs += T -> l -> childs;
        if (T -> r) T -> childs += T -> r -> childs;
    }

    else {
        T -> sum += a -> key;
        ++T -> childs;

        if (a -> key < T -> key) insert(T -> l, a);
        else insert(T -> r, a);
    }
}



void merge (Treap& T, Treap L, Treap R) {
    if (not L) T = R;
    else if (not R) T = L;

    else if (L -> pr > R -> pr) {
        merge (L -> r, L -> r, R);
        T = L;
    }

    else {
        merge (R -> l, L, R -> l);
        T = R;
    }
}


void erase (Treap& T, ll k) {
    if (T -> key == k) merge (T, T -> l, T -> r);
    
    else {
        if (k < T -> key) erase (T -> l, k);
        else erase (T -> r, k);
    }
}

bool find (Treap T, ll k){
    if (not T) return false;

    if (T -> key == k) {
        T -> sum += k;
        T -> childs++;
        return true;
    }

    T -> childs++;
    T -> sum += k;

    if (k < T -> key) {
        if (find(T -> l, k)) return true;
        else{
            T -> childs--;
            T -> sum -= k;
            return false;
        }
    }
    else {
        if (find(T -> r, k)) return true;
        else{
            T -> childs--;
            T -> sum -= k;
            return false;
        }
    }
}

ll anti_amount_right (Treap T, int k);
ll anti_amount_left (Treap T, int k);


ll anti_amount_right (Treap T, int k){
    if (not T) return 0;

    if (T -> key <= k) return anti_amount_right(T -> r, k);
    return T -> childs - anti_amount_left(T -> l, k+1);
}

ll anti_amount_left (Treap T, int k){
    if (not T) return 0;

    if (T -> key >= k) return anti_amount_left(T -> l, k);
    return T -> childs - anti_amount_right(T -> r, k-1);
}


ll anti_sum_right (Treap T, int k);
ll anti_sum_left (Treap T, int k);


ll anti_sum_right (Treap T, int k){
    if (not T) return 0;

    if (T -> key <= k) return anti_sum_right(T -> r, k);
    return T -> sum - anti_sum_left(T -> l, k+1);
}

ll anti_sum_left (Treap T, int k){
    if (not T) return 0;

    if (T -> key >= k) return anti_sum_left(T -> l, k);
    return T -> sum - anti_sum_right(T -> r, k-1);
}

int main() {
    srand (time(NULL));

    Treap T = nullptr;

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i){
        int operation;
        cin >> operation;

        if (operation == 1){
            int x;
            cin >> x;

            if (not find(T, x)){
                Treap a = new Node {x, rand(), x, 1, nullptr, nullptr};
                insert(T, a);
            }
        }

        if (operation == 2) {
            int l, r;
            cin >> l >> r;
 
            if (not T) cout << 0 << '\n';
            else cout << T -> childs - anti_amount_left(T, l) - anti_amount_right(T, r) << '\n';
        }

        if (operation == 3){
            int l, r;
            cin >> l >> r;

            if (not T) cout << 0 << '\n';
            else cout << T -> sum - anti_sum_left(T, l) - anti_sum_right(T, r) << '\n';
        }
    }
}   