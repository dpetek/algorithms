/*
ID: dpetek11
LANG: C++
TASK: agrinet
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
int n;
int graph[102][102];
int dist[102];
#define INF (1<<29)


int mst(int start){
    int ret = 0;
    priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > Q;
    for (int i=0;i<n;++i) dist[i] = INF;
    Q.push(make_pair(0,start));
    int cnt = 0;
    while( cnt  < n ){
        int c = Q.top().sc;
        int d = Q.top().fs;
        Q.pop();
        if ( dist[c] != INF ) continue;
        ret+=d;
        ++cnt;
        dist[c] = d;
        for (int i=0;i<n;++i){
            if ( i == c ) continue;
            if ( dist[i] != INF ) continue;
            Q.push(make_pair(graph[c][i], i));
        }

    }
    return ret;
}

int main(void){
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);

    scanf("%d", &n);

    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            scanf("%d", &graph[i][j]);
        }
    }
    printf ("%d\n", mst(0));
    return 0;
}
