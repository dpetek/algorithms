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

priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > disc;
set<int> onDisc;
vector<int> movies;
set<int> usage[10005];
int  n, cap;

int main(void){
    int tmp;
    scanf ("%d %d", &n, &cap);
    for (int i=0;i<n;++i){
        scanf("%d", &tmp);
        movies.pb(tmp);
        usage[tmp].insert(i);
    }
    for (int i=0;i<=10000;++i){
        if (usage[i].size() ) usage[i].insert(1e6);
    }

    int changes = 0;

    for (int i=0;i<movies.size();++i){
        usage[movies[i]].erase(usage[movies[i]].begin());
        if ( onDisc.find(movies[i]) != onDisc.end()) continue;
        ++changes;
        if ( onDisc.size() < cap ){
            onDisc.insert(movies[i]);
        }else{
            int maxy = 0;
            set<int> :: iterator toRem = onDisc.begin();

            for (set<int> :: iterator it = onDisc.begin();it != onDisc.end();++it){
                if ( *(usage[*it].begin()) > maxy){
                    maxy = *(usage[*it].begin());
                    toRem = it;
                }
            }

            onDisc.erase(toRem);
            onDisc.insert(movies[i]);
        }
    }

    printf ("%d\n", changes);

    return 0;
}
