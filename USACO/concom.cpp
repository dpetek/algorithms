/*
ID: dpetek11
LANG: C++
TASK: concom
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

int rel[110][110];
bool ctrl[110][110];
vector<int> controling[110];

int main(void){
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);

    int n;
    int a, b, c;
    scanf("%d", &n);

    for (int i=0;i<n;++i){
        scanf("%d %d %d", &a, &b, &c);
        rel[a][b] = c;

        if ( c > 50 ){
            controling[a].pb(b);
            ctrl[a][b] = 1;
        }
    }


    while(true){
        bool changeDone = false;

        for (int i=1;i<=100;++i){
            for (int j=1;j<=100;++j){
                if ( ctrl[i][j] ) continue;
                int cnt = rel[i][j];
                for (int k=0;k<controling[i].size();++k){
                    cnt += rel[controling[i][k]][j];
                }
                if ( cnt > 50 ){
                    ctrl[i][j] = true;
                    controling[i].pb(j);
                    changeDone = true;
                }
            }
        }
        if ( !changeDone ) break;
    }
    set<pair<int,int> > v;

    for (int i=1;i<=100;++i){
        for (int j=0;j<controling[i].size();++j){
            if ( i == controling[i][j] ) continue;
            v.insert(make_pair(i,controling[i][j]));
        }
    }

    for(set<pair<int,int> > :: iterator it = v.begin();it != v.end();++it){
        printf("%d %d\n", it->fs, it->sc);
    }

    return 0;
}
