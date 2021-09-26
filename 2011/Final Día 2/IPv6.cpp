#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <string>

using namespace std;
typedef long long int ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;


void apply1(string& s){
    s.push_back(':');

    string ans = ":";
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == '0' and ans.back() == ':') continue;
        if (s[i] == ':' and ans.back() == ':') {
            if (i == 0 or s[i-1] != ':') {
                if (i > 0 and s[i-1] != ':') ans.push_back('0');
            }
        }
        ans.push_back(s[i]);
    }

    ans.pop_back();
    ans.erase(ans.begin());
    s = ans;
}

void apply2(string& s){
    string ans;

    int maximum = 3;
    int current = 0, temp = 0;
    int index = -1;

    for (int i = 0; i < s.size(); ++i){
        if (s[i] == ':') {
            ++temp;
            continue;
        }
        if (s[i] == '0' and (i == 0 or s[i-1] == ':' or s[i-1] == '0')) {
            ++current;
            ++temp;
        }
        else {
            if (current > maximum){
                maximum = current;
                index = i - temp;
            }
            current = 0;
            temp = 0;
        }
    }
    if (current > maximum){
        maximum = current;
        index = s.size() - temp;
    }

    for (int i = 0; i < s.size(); ++i){
        if (i == index){
            if (i == 0) ans.push_back(':');
            else if (ans.back() != ':') ans.push_back(':');
            while (i < s.size() and (s[i] == '0' or s[i] == ':')) ++i;
            ans.push_back(':');
            if (i < s.size() and ans[i] != ':') ans.push_back(s[i]);
        }
        else ans.push_back(s[i]);
    }

    s = ans;
}

void complete(string& s){
    vector <string> sequence;

    string current;
    if (s[0] == ':' and s[1] == ':') s.erase(s.begin());
    if (s.back() != ':') s.push_back(':');

    for (int i = 0; i < s.size(); ++i){
        if (s[i] == ':'){
            sequence.push_back(current);
            current = "";
        }
        else current.push_back(s[i]);
    }

    for (int i = 0; i < sequence.size(); ++i){
        if (sequence[i].size() == 0){
            sequence.erase(sequence.begin() + i);
            while (sequence.size() < 8) sequence.insert(sequence.begin() + i, "0000");
        }

        while (sequence[i].size() < 4) sequence[i].insert(sequence[i].begin(), '0');
    }

    string ans;
    for (int i = 0; i < sequence.size(); ++i){
        if (i > 0) ans.push_back(':');
        ans += sequence[i];
    }

    s = ans;
}

int main (){
    char c;
    cin >> c;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;

        if (c == '2') apply2(s);
        if (c == 'C') complete(s);
        else apply1(s);
        

        cout << s << endl;
    }
}