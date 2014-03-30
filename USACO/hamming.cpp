/*
ID: dpetek11
LANG: C++
TASK: hamming
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

int dist[(1<<9)+1][(1<<9)+1];

int main(void){
    freopen("hamming.in", "r", stdin);
    freopen("hamming.out", "w", stdout);

    int n, b, d;

    scanf ("%d %d %d", &n, &b, &d);

    for (int i=0;i<(1<<(b+1));++i){
        for(int j=i+1;j<(1<<(b+1));++j){
            dist[i][j] = dist[j][i] = __builtin_popcount(i^j);
        }
    }

    vector<int> sol;
    sol.pb(0);
    for (int i=1;i < (1<<(b+1)) && sol.size()<n;++i){

        bool ok = true;
        for (int j=0;j<sol.size();++j){
            if (dist[i][sol[j]] < d){
                ok = false;
                break;
            }
        }

        if (ok) sol.pb(i);
    }

    for (int i=0;i<sol.size();++i){
        if ( i && i % 10 == 0) printf ("\n");
        printf("%s%d", (i%10==0) ? "" : " ", sol[i]);
    }
    printf ("\n");

    return 0;
}
