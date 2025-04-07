#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second

vii fge;
vii bridges;
vi dude;
 
int cc = 1;
 
void bdfs(int v, int p, const vvi &al, vi &ambe, vi &depth, vi &rep){
	int mbe = depth[v];
	for(auto &u : al[v]){
		if(u == p)
			continue;
		if(depth[u] == -1){
			depth[u] = depth[v]+1;
			bdfs(u, v, al, ambe, depth, rep);
			mbe = min(mbe, ambe[u]);
			
		}
		else{
			if(depth[u] < depth[v])fge.pb(ii(v,u)); //backedge
			mbe = min(mbe, depth[u]);
		}
	}
		
	if(v == 0)
		return;
	
	if(mbe == depth[v]){
		// pv is bridge
		rep[v] = cc; //new compo
		dude.pb(v);
		cc++;
		bridges.pb(ii(p,v));
	}
	else{
		//it is not
		rep[v] = -1;
		fge.pb(ii(p,v));
	}
	
	ambe[v] = mbe;
}
 
 
void repdfs(int v, int p, const vvi &al, vi &rep, vb &visited){
	visited[v] = true;
	for(auto &u : al[v]){
		if(u == p)
			continue;
		if(rep[u] == -1){
			rep[u] = rep[v];
		}
		if(not visited[u])
			repdfs(u, v, al, rep, visited);
	}
}
 
void tree_dfs(int v, const vector<vector<pair<int, ii>>> &al, 
	vector<pair<int, ii>> &par, vi &leaves){
	if(al[v].size() == 1){
		leaves.pb(v);
		return;
	}
	
	for(auto [u, e] : al[v]){
		if(par[v].fi != u){
			par[u] = make_pair(v, e);
			tree_dfs(u, al, par, leaves);
		}
	}
}
 
void do_tree(int n, vector<vector<pair<int, ii>>> &tal){ //new n
	vector<pair<int, ii>> par(n, make_pair(-1, ii(-1, -1)));
	vi leaves;
	int root = 0;
	for(int i = 0; i < n; i++){
		if(tal[i].size() > 1){
			root = i;
			break;
		}
	}
	
	tree_dfs(root, tal, par, leaves);
	int k = leaves.size();
    
    //handle edge case by reversing leaves vector if needed
    int l1 = leaves[k/2-1];
    while(par[l1].fi != root)
    	l1 = par[l1].fi;
    int l2 = leaves[k-1];
    while(par[l2].fi != root)
    	l2 = par[l2].fi;
    
    if(l1 == l2)
    	reverse(leaves.begin(), leaves.end());
    
    vb done_above(n, false);
    done_above[root] = true;
    
    //print number of edges of the we need to add
    cout << (k+1)/2 << endl; 
    
    //save oriented bridges
    for(int i = 0; i < k; i++){
    	int v = leaves[i];
    	while(not done_above[v]){
    		if(i < k/2)
	    		fge.pb(ii(par[v].se.fi, par[v].se.se));
    		else
    			fge.pb(ii(par[v].se.se, par[v].se.fi));
    		done_above[v] = true;
    		v = par[v].fi;
    	}
    }
    
    //save added edges
    for(int i = 0; i < k/2; i++){
    	fge.pb(ii(dude[leaves[i]], dude[leaves[i + k/2]]));
    }
    if(k%2 == 1){
    	fge.pb(ii(dude[leaves[(k-1)/2-1]], dude[leaves[k-1]]));
    }
}
 
 
void test_case(){
	int n, m;
    cin >> n >> m;
    vvi al(n);
    
    fge.clear();
    bridges.clear();
    dude.clear();
    cc = 1;
	
    for(int i = 0; i < m; i++){
    	int a,b;
    	cin >> a >> b;
    	a--; b--;
    	al[a].pb(b);
    	al[b].pb(a);
    }
    
    vi ambe(n, -1);
    vi depth(n, -1);
    vi rep(n, -1);
    dude.pb(0);
    depth[0] = 0;
    rep[0] = 0;
    
    bdfs(0, -1, al, ambe, depth, rep);
    
    
    vb visited(n, false);
    repdfs(0, -1, al, rep, visited);
    
    if(cc == 1){
    	cout << 0 << endl;
    }
    if(cc == 2){
    	cout << 1 << endl;
    	fge.pb(ii(dude[1], dude[0]));
    	fge.pb(ii(bridges[0].fi, bridges[0].se));
    }
    else if(cc >= 3){
    	vector<vector<pair<int, ii>>> tal(cc);
	    for(auto [u,v] : bridges){
	    	tal[rep[u]].pb(make_pair(rep[v], ii(u,v)));
	    	tal[rep[v]].pb(make_pair(rep[u], ii(v,u)));
	    }
	    do_tree(cc, tal);
    }
    
    // print resulting graph
	for(auto e : fge){
		cout << e.fi+1 << ' ' << e.se+1 << endl;
	}
}
 
signed main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
   	while(t--){
   		test_case();
   		cout << endl;
   	}
}
