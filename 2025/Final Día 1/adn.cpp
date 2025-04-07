#include<bits/stdc++.h>

using namespace std;

vector<string> id_to_triangle(vector<string> v) {
    if (v[1] < v[2]) {
        return {v[1], v[2], v[3], v[0]};
    }
    if (v[1] > v[2]) {
        return {v[3], v[0], v[2], v[1]};
    }
    return {v[2], v[0], v[3], v[0]};
}

vector<string> triangle_to_id(vector<string> w) {
    if (w[1] < w[3]) {
        return {w[3], w[0], w[1], w[2]};
    }
    if (w[1] > w[3]) {
        return {w[1], w[3], w[2], w[0]};
    }
    return {w[1], w[0], w[0], w[2]};
}

string triangle_to_dna(string s, string t) {
    int n = s.length();
    string dna(n, '-');
    int aidx = -1;
    int acnt = 0;
    for (int i=0; i < n; ++i) {
        if (aidx == -1) {
            if (s[i] == t[i]) {
                dna[i] = (s[i] == '0' ? 'G' : 'T');
            }
            else {
                dna[i] = 'A';
                aidx = i;
                acnt++;
            }
        }
        else { 
            dna[i] = (s[i] == '0' ? (t[i] == '0' ? 'A' : 'C') : (t[i] == '0' ? 'G' : 'T'));
            if (dna[i] == 'A') acnt++;
        }
    }
    if (acnt%2 == 0) dna[aidx] = 'C';
    return dna;
}

pair<string, string> dna_to_triangle(string dna) {
    int n = dna.length();
    string s(n, '0');
    string t(n, '0');
    int aidx = -1;
    for (int i=0; i < n; ++i) {
        if (aidx == -1) {
            if (dna[i] == 'G') {
                s[i] = t[i] = '0';
            }
            else if (dna[i] == 'T') {
                s[i] = t[i] = '1';
            }
            else {
                t[i] = '1';
                s[i] = '0';
                aidx = i;
            }
        }
        else {
            switch (dna[i]) {
                case 'A':
                    s[i] = '0';
                    t[i] = '0';
                    break;
                case 'C':
                    s[i] = '0';
                    t[i] = '1';
                    break;
                case 'G':
                    s[i] = '1';
                    t[i] = '0';
                    break;
                case 'T':
                    s[i] = '1';
                    t[i] = '1';
                    break;
                default:
                    break;
            }

        }
    }
    return {s, t};
}

vector<string> triangle_to_dna_pairs(vector<string> v) {
    return {triangle_to_dna(v[0], v[1]), triangle_to_dna(v[2], v[3])};
}

vector<string> dna_pairs_to_triangle(vector<string> v) {
    auto p1 = dna_to_triangle(v[0]);
    auto p2 = dna_to_triangle(v[1]);
    return {p1.first, p1.second, p2.first, p2.second};
}


vector<string> id_to_dna(vector<string> v) {
    return triangle_to_dna_pairs(id_to_triangle(v));
}

vector<string> dna_to_id(vector<string> v) {
    return triangle_to_id(dna_pairs_to_triangle(v));
}

int main() {
    int n;
    cin >> n;
    int b;
    cin >> b;
    if (b == 0) { //id -> dna
        vector<string> v(4);
        cin >> v[0] >> v[1] >> v[2] >> v[3]; 
        vector<string> w = id_to_dna(v);
        cout << w[0] << " " << w[1] << endl;
    }
    if (b == 1) { //dna -> id
        vector<string> w(2);
        cin >> w[0] >> w[1];
        vector<string> v = dna_to_id(w);
        cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
    }
}