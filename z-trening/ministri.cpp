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

vector<int> graph[30002];
char color[30002]={0};
int fr[30002];
int n;
int fill(int start, int clr){
    int cnt = 0;
    queue<pair<int,int> > Q;
    Q.push(make_pair(0,start));
    while ( !Q.empty()){
        int node = Q.front().sc;
        int step = Q.front().fs;
        Q.pop();

        if ( color[node]  ) return step - color[node];
        color[node] = step;

        for (int i=0;i<graph[node].size();++i){
            Q.push(make_pair(step+1,graph[node][i]));
        }
    }
    return cnt;
}

int main(void){
    int tmp;
    scanf ("%d", &n);
    int maxy = 0;
    for (int i=0;i<n;++i){
        scanf("%d", &tmp);
        fr[i+1] = tmp;
        graph[tmp].pb(i+1);

    }
    int cl = 1, maxyColor;

    for (int i=1;i<=n;++i){
        memset(color, 0, sizeof(color));
        int buff = fill(i, cl++);
        if ( buff > maxy ){
            maxy = buff;
            maxyColor = cl-1;
        }

    }
    for (int i=1;i<=n;++i){

        if ( fr[i] == i && color[i] != maxyColor) ++ maxy;
    }

    printf ("%d\n", maxy);
    return 0;
}
