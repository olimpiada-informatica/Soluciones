
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {

	int T;
	cin >> T;
	while(T--) {
	int n, m;
	cin >> n >> m;
	
	if(n&1 || m&1) {
		cout << "NO" << endl;
	    continue;
	}
	cout << "SI" << endl;

	bool transp = false;
	if(n > m) {
        transp = true;
        swap(n, m);
    }
    
    vvi grid = vvi(n, vi(m, 0));
    if(n == 2) {
    	if(m == 2) {
    		grid[0][0] = 1;
    		grid[1][0] = 1;
    	}
    	else {
	        for(int j=0; j < m-m%4; j+=4) {
	                grid[0][j] = 1;
	                grid[0][j+1] = 1;
	                grid[0][j+2] = 1;
	                grid[1][j+2] = 1;
	            }
	        if(m%4 == 2) {
	            grid[0][m-3] = 1;
	            grid[1][m-1] = 1;
	        }
        }
    }
    else {
        
        for(int j=0; j < m; j+=2) {
            for(int i=0; i < n; ++i) {
                grid[i][j] = 1;
            }
        }
        for(int j=n; j < m; j += 2) {
            grid[1][j-1] = 1;
            grid[0][j]  = 0;
        }
    }
    
    if(transp) {
        for(int i=0; i < m; ++i) {
            for(int j=0; j < n; ++j) {
                cout << (grid[j][i] ? "#" : ".");
            }
            cout << endl;
        }
    }
    else {
        for(int i=0; i < n; ++i) {
            for(int j=0; j < m; ++j) {
                cout << (grid[i][j] ? "#" : ".");
            }
            cout << endl;
        }
    }
	
	}

}

