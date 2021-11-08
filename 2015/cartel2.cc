#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

struct node{
	string s = "";
	bool isEnd = true;
	map<char, node*> child;
	node(string r){
		s = r;
	}

	node* add(string& s1, int i) {
		for(int j = 0; j < s.size() and i+j < s1.size(); ++j) {
			if(s[j] != s1[i+j]) {
				node* nuevo1 = new node(s.substr(0, j));
				node* nuevo2 = new node(s1.substr(i+j+1));
				nuevo1->isEnd = false;
				nuevo2->isEnd = true;
				nuevo1->child[s1[i+j]] = nuevo2;
				nuevo1->child[s[j]] = this;
				s = s.substr(j+1);
				return nuevo1;
			}
		}

		if(s1.size() - i == s.size()){
			this->isEnd = true;
			return this;
		} else if(s1.size() - i < s.size()){
			node* nuevo = new node(s.substr(0, s1.size() - i));
			nuevo->isEnd = true;
			nuevo->child[s[s1.size() - i]] = this;
			s = s.substr(s1.size() - i+1);
			return nuevo;
		}

		if(child[s1[i+s.size()]]) {
			child[s1[i+s.size()]] = child[s1[i+s.size()]]->add(s1, i+s.size()+1);
		} else {
			child[s1[i+s.size()]] = new node(s1.substr(i+s.size()+1));
		}
		return this;
	}
};

typedef node* trie;

vector<ll> traducir(string &s, trie root){
	int n = s.size();
	vector<ll> dp(n+1, 0);
	dp[0] = 1;
	int last = 0;
	for (int i = 0; i <= last; i++){
		if (dp[i] == 0)
			continue;
		trie act = root;
		int idx = i;
		while (act and idx <= n){
			bool works = act->s.size() <= s.size() - idx;
			for (int j = 0; j < act->s.size() and works; j++){
				if (act->s[j] != s[j+idx])
					works = false;
			}
			if (!works)
				break;
			idx += act->s.size();
			if (act->isEnd){
				dp[idx] = (dp[idx] + dp[i])%MOD;
				last = max(last, idx);
			}
			if (idx < n)
				act = act->child[s[idx]];
			idx++;
		}
	}
	return dp;
}

int main(){
	int k, r;
	cin >> k;
	trie rootK = new node("");
	rootK->isEnd = false;
	while (k--){
		string s;
		cin >> s;
		rootK->add(s, 0);
	}

	trie rootR = new node("");
	rootR->isEnd = false;
	cin >> r;
	while (r--){
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		rootR->add(s, 0);
	}

	string s;
	cin >> s;
	int n = s.size();
	vector<ll> tradK = traducir(s, rootK);
	reverse(s.begin(), s.end());
	vector<ll> tradR = traducir(s, rootR);
	ll ans = 0;
	for (int i = 0; i <= n; i++){
		ans = (ans + tradK[i]*tradR[n-i])%MOD;
	}
	cout << ans << '\n';
}