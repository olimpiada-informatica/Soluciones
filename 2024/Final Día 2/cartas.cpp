#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>

vi order;
int ask(int a, int b){
    cout << "? " << order[a]+1 << " " << order[b]+1 << endl;
    int x;
    cin >> x;
    return x-1;
}

signed main(){
    int n;
    cin >> n;
    order=vi(n);
    for (int i=0;i<n;i++) order[i]=i;
    mt19937 rng;
    shuffle(order.begin(),order.end(),rng);

    vi res(n,-1);
    
    int a=0,b=1,minab=ask(a,b);
    for (int i=2;i<n;i++){
        int x=ask(a,i);
        if (x==minab){ //extra query
            res[order[a]]=x;
            a=i;
            minab=ask(a,b);
        }
        else if (x<minab) res[order[i]]=x;
        else{
            res[order[b]]=minab;
            b=i;
            minab=x;
        }
    }
    res[order[a]] = res[order[b]] = n-2;
    cout << "! ";
    for (int x:res) cout << x+1 << " ";
    cout << endl;
}
