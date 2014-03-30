/*
ID: dpetek11
LANG: C++
TASK: comehome
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
#define INF (1<<29)
vector< pair<int,int> > graph[300];

int dist[300];

pair<int,int>  dijkstra(int start){
    for (int i=0;i<300;++i) dist[i] = INF;
    dist[start] = 0;

    priority_queue<pair<int,int>  , vector<pair<int,int> > , greater<pair<int,int> > >Q;

    Q.push(make_pair(0, start));
    while ( !Q.empty()){
        int d = Q.top().fs;
        int c = Q.top().sc;
        Q.pop();
        if ( c >= 'A' && c <= 'Y') return make_pair(c, d);

        if ( d <= dist[c] ){

            for (int i=0;i<graph[c].size();++i){
                int nc = graph[c][i].fs;
                int nd = d + graph[c][i].sc;

                if ( nd < dist[nc] ){
                    dist[nc] = nd;
                    Q.push(make_pair(nd, nc));
                }
            }
        }
    }
    return make_pair(-1, -1);
}

int main(void){
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    int n, d;
    char tmp1[5], tmp2[5];
    scanf("%d", &n);

    for (int i=0;i<n;++i){
        scanf("%s %s %d", tmp1,tmp2, &d);
        graph[tmp1[0]].pb(make_pair(tmp2[0], d));
        graph[tmp2[0]].pb(make_pair(tmp1[0], d));
    }
    pair<int,int> res = dijkstra((int)'Z');
    printf ("%c %d\n", res.fs, res.sc);

    return 0;
}
