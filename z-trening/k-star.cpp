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

vector<int> graph[100003];
int used[100005];
int n, K;


bool okChain(int start, int deg){

    queue<int> Q;
    Q.push(start);
    int cnt = 0;
    while ( !Q.empty()){
        int node = Q.front();
        Q.pop();

        if ( used[node] == start || used[node] < 0 ) continue;
        used[node] = start;
        ++cnt;
//        printf ("%d[%d/%d]->", node, cnt, deg);
        int num = 0;
        for (int i=0;i<graph[node].size();++i){
            if ( used[graph[node][i]] < 0 || used[graph[node][i]]==start) continue;
            ++num;
            Q.push(graph[node][i]);
        }
        if ( num > 1 ) return false;

    }
    return cnt == deg;
}

bool solve(){
    if ( (n - 1) % K != 0 ) return false;
    int deg = (n-1)/K;
    bool found = false;
    vector<int> roots;

    for (int i=0;i<=100000;++i){
        if ( graph[i].size() == deg ) {found = true;roots.pb(i);}
    }

    if ( !found ) return false;

    for (int j=0;j<roots.size();++j){
        int root = roots[j];
        memset(used, 0, sizeof(used));
        used[root]=-1;
//        printf ("Root is %d\n", root);
        bool allOk = true;
        for (int i=0;i<graph[root].size();++i){
//            printf ("Checking chain starting on %d\n", graph[root][i]);
            if ( !okChain(graph[root][i], K)){allOk = false;break;}
//            printf ("\n");
        }
        if ( allOk ) return true;
    }

    return false;
}

int main(void){
    int a, b;
    scanf ("%d %d", &n, &K);

    for (int i=0;i+1<n;++i){
        scanf("%d %d", &a, &b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    bool res = solve();
    printf ("%s\n", res ? "Da" : "Ne");

    return 0;
}
