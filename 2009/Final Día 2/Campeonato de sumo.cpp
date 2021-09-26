#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;

struct results{
    int points;
    string name;
};

bool comp(results& a, results& b){
    if (a.points != b.points) return a.points > b.points;
    return a.name < b.name;
}

bool comp2(vi& a, vi& b){
    int aa = min(a[0], a[1]);
    int bb = max(a[0], a[1]);

    int pta = 0, ptb = 0;

    if ((aa/2 == 0 and bb/2 == 1) or (aa/2 == 2 and bb/2 == 3)) pta = 1;
    if ((aa/4 == 0 and bb/4 == 1)) pta = 2;

    aa = min(b[0], b[1]);
    bb = max(b[0], b[1]);

    if ((aa/2 == 0 and bb/2 == 1) or (aa/2 == 2 and bb/2 == 3)) ptb = 1;
    if ((aa/4 == 0 and bb/4 == 1)) ptb = 2;

    if (pta != ptb) return pta < ptb;
    return a[2] < b[2];
}

vector <string> cuart(8);
vector <int> cuartos = {0, 1, 2, 3, 4, 5, 6, 7};
vector <int> semifinal(4, -1);
vector <int> final(2, -1);
vector <int> ganador(1, -1);

vector <bool> cu(4, false);
vector <bool> sem(2, false);
vector <bool> fin(1, false);

void combat(int aa, int bb){    
    int a = min(aa, bb);
    int b = max(aa, bb);


    if (a == 0 and b == 1){
        if (not cu[0]){
            cu[0] = true;
            semifinal[0] = aa;
        }
        return;
    }
    if (a == 2 and b == 3){
        if (not cu[1]){
            cu[1] = true;
            semifinal[1] = aa;
        }
        return;
    }
    if (a == 4 and b == 5){
        if (not cu[2]){
            cu[2] = true;
            semifinal[2] = aa;
        }
        return;
    }
    if (a == 6 and b == 7){
        if (not cu[3]){
            cu[3] = true;
            semifinal[3] = aa;
        }
        return;
    }

    if (a/2 == 0 and b/2 == 1){
        if (a == semifinal[0] and b == semifinal[1]){
            if (not sem[0]){
                sem[0] = true;
                final[0] = aa;
            }
        }
        return;
    }
    if (a/2 == 2 and b/2 == 3){
        if (a == semifinal[2] and b == semifinal[3]){
            if (not sem[1]){
                sem[1] = true;
                final[1] = aa;
            }
        }
        return;
    }

    if (a == final[0] and b == final[1]){
        if (not fin[0]){
            fin[0] = true;
            ganador[0] = aa;
        }
    }
}   

int main (){
    vi V(4);
    vector <vector <string> > robots(4);

    map <string, int> M;
    int cnt = 0, total = 0, combats = 0;

    for (int i = 0; i < 4; ++i){
        cin >> V[i];
        total += V[i];
        combats += (V[i] * (V[i] - 1))/2;

        for (int j = 0; j < V[i]; ++j){
            string s;
            cin >> s;
            robots[i].push_back(s);
            M[s] = cnt++; 
        }
    } 
    
    vector <vector <bool> > played(total, vector <bool> (total, true));
    vi points(total, 0);

    int sum = 0;
    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < V[i]; ++j){
            for (int k = 0; k < j; ++k){
                played[k+sum][j+sum] = false;
            }
        }

        sum += V[i];
    }

    vvi partidos_final;
    int cnt2 = 0;

    string a, b;
    int x;
    while (cin >> a >> b >> x){
        if (x == 2) swap(a, b); //a winner, b looser

        int aa = M[a];
        int bb = M[b];

        if (combats == 0){ //final
            if (aa >= 0 or bb >= 0) continue;
            if (fin[0]) continue;

            aa = -aa - 1;
            bb = -bb - 1;

            partidos_final.push_back({aa, bb, cnt2++});
        }
        else { // liguilla
            int aaa = min(aa, bb);
            int bbb = max(aa, bb);

            if (played[aaa][bbb]) continue;
            played[aaa][bbb] = true;
            ++points[aa];
            --combats;

            if (combats == 0){
                vector <vector <results> > W(4);

                sum = 0;

                for (int i = 0; i < 4; ++i){
                    for (int j = 0; j < V[i]; ++j){
                        W[i].push_back({points[sum + j], robots[i][j]});
                    }

                    sort(W[i].begin(), W[i].end(), comp);
                    
                    if (i == 0){
                        cuart[0] = W[i][0].name;
                        M[W[i][0].name] = -1;
                        cuart[7] = W[i][1].name;
                        M[W[i][1].name] = -8;
                    }
                    else if (i == 1){
                        cuart[2] = W[i][0].name;
                        M[W[i][0].name] = -3;
                        cuart[5] = W[i][1].name;
                        M[W[i][1].name] = -6;
                    }
                    else if (i == 2){
                        cuart[3] = W[i][1].name;
                        M[W[i][1].name] = -4;
                        cuart[4] = W[i][0].name;
                        M[W[i][0].name] = -5;
                    }
                    else {
                        cuart[1] = W[i][1].name;
                        M[W[i][1].name] = -2;
                        cuart[6] = W[i][0].name;
                        M[W[i][0].name] = -7;
                    }

                    sum += V[i];
                }

                for (int i = 0; i < 8; ++i) cout << cuart[i] << endl;
            }
        }
    }

    if (combats > 0) cout << "??" << endl;
    
    for (int i = 0; i < partidos_final.size(); ++i){
        combat(partidos_final[i][0], partidos_final[i][1]);
    }

    if (fin[0]){
        cout << "-----" << endl;
        vector <bool> used(8, false);

        cout << cuart[ganador[0]] << endl;
        used[ganador[0]] = true;

        for (int i = 0; i < 2; ++i){
            if (used[final[i]]) continue;
            used[final[i]] = true;
            cout << cuart[final[i]] << endl;
        }

        set <string> S;
        for (int i = 0; i < 4; ++i){
            if (used[semifinal[i]]) continue;
            used[semifinal[i]] = true;

            S.insert(cuart[semifinal[i]]);
        }

        bool first = true;
        for (auto x: S) {
            if (first) first = false;
            else cout << " ";
            cout << x;
        }
        cout << endl;
        S.clear();

        for (int i = 0; i < 8; ++i){
            if (used[cuartos[i]]) continue;
            used[cuartos[i]] = true;

            S.insert(cuart[cuartos[i]]);
        }
        first = true;
        for (auto x: S) {
            if (first) first = false;
            else cout << " ";
            cout << x;
        }
        cout << endl;
    }
}