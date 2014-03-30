/*
ID: dpetek11
LANG: C++
TASK: checker
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <cmath>
#define pb push_back
#define fs first
#define sc second
#define foreach(c,it) for(typeof(((c).begin())) it=((c).begin());(it)!=((c).end());++(it))
#define _sz(c) ((int)c.size())
#define cstr(s) ((s).c_str())
using namespace std;
int n, cnt = 0;
vector<int> sol;
char used[15];
char usedDiagonal[40];
char usedDiagonal2[60];
vector<int> av;
bool state[15][15];
int cntFree[15];

void rec(int pos){
    if ( pos == sol.size()){
        if ( cnt < 3 ){
            for (int i=0;i<sol.size();++i) printf ("%s%d", i ? " " : "", sol[i] + 1);
            printf ("\n");
        }
        ++cnt;
        return;
    }

    for (int i=0;i<n;++i){
        if (!used[i] && !usedDiagonal[i+pos] && !usedDiagonal2[pos - i + 27]){
            sol[pos] = i;
            used[i] = usedDiagonal[i+pos] = usedDiagonal2[pos - i + 27] = true;
            rec (pos + 1);
            used[i] = usedDiagonal[i+pos] = usedDiagonal2[pos - i + 27] = false;
        }
    }
}

int main(void){
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);

    scanf("%d", &n);
    sol.resize(n, -1);

    for (int i=0;i<n;++i) av.pb(i);

    rec(0);
    printf ("%d\n", cnt);

    return 0;
}
