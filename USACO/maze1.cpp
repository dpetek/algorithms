/*
ID: dpetek11
LANG: C++
TASK: maze1
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

vector<int> graph[4000];
int node_id[210][100];
vector<string> board;
int w, h;
char buffer[101];

int maxy = 0;
int dist[4000];


void dijkstra(int start){
    priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > Q;
    Q.push(make_pair(1,start));
    dist[start] = 1;
    while ( !Q.empty()){
        int d = Q.top().fs;
        int c = Q.top().sc;
        Q.pop();

        for (int i=0;i<graph[c].size();++i){
            int ndist = d + 1;
            int nc = graph[c][i];
            if ( dist[nc] > ndist ){
                dist[nc] = ndist;
                Q.push(make_pair(ndist, nc));
            }
        }
    }
}

int main(void){
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);

    scanf("%d %d\n", &w, &h);

    int id = 1;
    for (int i=0;i<2*h+1;++i){
        fgets(buffer, 100, stdin);
        buffer[2*w+1]='\0';
        if ( i % 2 != 0 ){
            for (int j=1;j<2*w+1;j+=2){
                node_id[i][j] = id++;
            }
        }
        board.pb(buffer);
    }

    vector<int> start;

    for (int i=1;i<board.size();i+=2){
        for (int j=1;j<2*w+1;j+=2){
            if ( board[i][j-1] != '|' ) {
                if ( j - 1 == 0 ) start.pb(node_id[i][j]);
                else graph[node_id[i][j]].pb(node_id[i][j-2]);
            }
            if ( board[i][j+1] != '|' ) {
                if ( j + 1 == 2*w ) start.pb(node_id[i][j]);
                else graph[node_id[i][j]].pb(node_id[i][j+2]);
            }
            if ( board[i-1][j] != '-' ) {
                if ( i - 1 == 0 ) start.pb(node_id[i][j]);
                else graph[node_id[i][j]].pb(node_id[i-2][j]);
            }
            if ( board[i+1][j] != '-' ) {
                if ( i + 2 >= board.size()) start.pb(node_id[i][j]);
                else graph[node_id[i][j]].pb(node_id[i+2][j]);
            }
        }
    }

    for (int i=0;i<=id;++i) dist[i] = INF;

    for (int i=0;i<start.size();++i){
        dijkstra(start[i]);
    }


    int maxy = 0;
    for (int i=1;i<id;++i) maxy=max(maxy, dist[i]);
    printf ("%d\n",maxy);

    return 0;
}
