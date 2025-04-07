#include<bits/stdc++.h>

using namespace std;

string xor_encode(string s) {
    string t;
    t.push_back(s[0]);
    int n = s.length();
    for (int i=0; i < n; ++i) {
        t.push_back(s[i] == t[i] ? '0' : '1');
    }
    return t;
}

string xor_decode(string s) {
    string t;
    int n = s.length();
    for (int i=0; i+1 < n; ++i) {
        t.push_back('0'+((s[i]-'0')^(s[i+1]-'0')));
    }
    return t;
}

string repetition_encode(string s) {
    const int B = 5;
    string t;
    for (char c : s) {
        for (int i=0; i < B; ++i) t.push_back(c);
    }
    return t;
}

string repetition_decode(string s) {
    const int B = 5;
    string t;
    vector<int> ct(2);
    for (char c : s) {
        ct[(c-'0')]++;
        if (ct[0]+ct[1] == B) {
            t.push_back(ct[0] > ct[1] ? '0' : '1');
            ct = vector<int>(2);
        }
    }
    return t;
}

const int L = 15;
const int B = 8;
vector<string> blocks;
string null_block;

int hamming_distance(string s, string t) {
    int n = s.length();
    assert(n == (int)t.length());
    int d = 0;
    for (int i=0; i < n; ++i) d += s[i] != t[i];
    return d;
}

void random_init(int seed) {
    mt19937 rng(seed);
    null_block = string(L, '0');
    for (int i=0; i < (1<<B); ++i) {
        string s;
        int min_dist;
        do {
            s = string();
            for(int j=0; j < L; ++j) s.push_back('0'+uniform_int_distribution<>(0, 1)(rng));
            min_dist = hamming_distance(s, null_block);
            for (int j=0; j < i; ++j) {
                min_dist = min(min_dist, hamming_distance(s, blocks[j]));
            }
        } while(min_dist < 3);
        blocks.push_back(s);
    }
    
}

int toint(string s) {
    int r = 0;
    for (int i=0; i < B; ++i) {
        if (s[i] == '1') r |= (1<<i);
    }
    return r;
}

string tostring(int r) {
    string s;
    for (int i=0; i < B; ++i) {
        s.push_back('0'+(r&1));
        r >>= 1;
    }
    return s;
}

string random_encode(string s) {
    int n = s.length();
    string t;
    for (int i=0; (i+1)*B <= n; ++i) {
        string block = s.substr(i*B, B);
        t += blocks[toint(block)];
    }
    t += null_block;
    if (n%B) {
        t += repetition_encode(s.substr(n-n%B));
    }
    return t;
}

string random_decode(string s) {
    int n = s.length();
    string t;
    for (int i=0; (i+1)*L <= n; ++i) {
        string block = s.substr(i*L, L);
        int md = hamming_distance(block, null_block);
        int mb = -1;
        for (int b=0; b < (1<<B); ++b) {
            int d = hamming_distance(block, blocks[b]);
            if (d < md) {
                md = d;
                mb = b;
            }
        }
        if (mb == -1) {
            if ((i+1)*L < n) {
                t += repetition_decode(s.substr((i+1)*L));
            }
            break;
        }
        else {
            t += tostring(mb);
        }
    }
    return t;
}

int main() {
    random_init(1337);
    string name;
    string str;
    cin >> name >> str;
    string out;
    if (name == "ENC") {
        if (str.length() <= 1e3) {
            out = "00000" + repetition_encode(str);
        }
        else {
            out = "11111" + random_encode(str);
        }
        out = xor_encode(out);
    }
    else if (name == "DEC") {
        str = xor_decode(str);
        cerr << str << endl;
        string pref = str.substr(0, 5);
        string suf = str.substr(5);
        int c0 = 0;
        for (char c : pref) c0 += (c == '0');
        if (c0 >= 3) {
            out = repetition_decode(suf);
        }
        else {
            out = random_decode(suf);
        }
    }
    cout << out << endl;
}