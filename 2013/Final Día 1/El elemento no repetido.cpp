#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stdlib.h>
#include <time.h> 
#include <cmath>
#include <random>
#include <chrono>

using namespace std;
typedef long long int ll;
typedef vector <int> vi;
typedef vector <vi> vvi;

mt19937 rng;

struct Node {
    ll key, pr;
    Node *l, *r;
};

typedef Node* Treap;

void split (Treap T, ll k, Treap& L, Treap& R){
    if (not T) L = R = nullptr;

    else if (k < T -> key) {
        split(T -> l, k, L, T -> l);
        R = T;
    }

    else {
        split(T -> r, k, T -> r, R);
        L = T;
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
    if (not T) return;
    
    if (T -> key == k) merge (T, T -> l, T -> r);

    else {
        if (k < T -> key) erase (T -> l, k);
        else erase (T -> r, k);
    }
}

bool find_value(Treap T, ll k){
    if (not T) return false;
    if (T -> key == k) return true;

    if (T -> key > k) return find_value(T -> l, k);
    else return find_value(T -> r, k);
}


int main() {
    rng = mt19937(std::chrono::steady_clock::now().time_since_epoch().count());

    Treap root = nullptr;

    ll x;
    while (cin >> x){
        if (find_value(root, x)) erase(root, x);
        else {
            Treap A = new Node{x, rng(), nullptr, nullptr};
            insert(root, A);
        }
    }

    cout << root -> key << endl;
}   