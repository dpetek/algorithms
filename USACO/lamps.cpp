/*
ID: dpetek11
LANG: C++
TASK: lamps
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

int n , c, a;

int main(void){
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);

    scanf("%d %d", &n, &c);

    string goal(n, 'x');

    while (true ){
        scanf("%d", &a);
        if ( a == -1 )break;
        goal[a-1] = 1;
    }

    while ( true){
        scanf("%d", &a);
        if ( a == -1) break;
        goal[a-1] = 0;
    }
    set<string>sol;

    for (int mask=0;mask<(1<<4);++mask){
        int pc = __builtin_popcount(mask);
        if ( pc > c ) continue;

        if ( (c-pc) % 2 != 0 ) continue;

        string tmp(n, 1);

        if ( mask & 1){
            for (int i=0;i<n;++i)tmp[i]=1-tmp[i];
        }

        if ( mask & 2){
            for (int i=0;i<n;i+=2) tmp[i] = 1-tmp[i];
        }

        if ( mask & 4){
            for (int i=1;i<n;i+=2) tmp[i] = 1-tmp[i];
        }

        if ( mask & 8 ){
            for(int i=0;3*i<n;++i) tmp[3*i] = 1-tmp[3*i];
        }

        bool ok = true;
        for (int i=0;i<n;++i){
            if ( (tmp[i] == 1 && goal[i] == 0) || (tmp[i]==0 && goal[i]==1))ok = false;
        }

        if ( ok){
            sol.insert(tmp);
        }
    }
    if ( sol.size() ){
        for(set<string> :: iterator it = sol.begin(); it != sol.end();++it){
            for (int i=0;i<it->size();++i) printf("%d", (*it)[i]);
            printf("\n");
        }
    }else printf ("IMPOSSIBLE\n");
    return 0;
}
