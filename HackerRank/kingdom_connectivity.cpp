#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <set>
#define pb push_back
#define fs first
#define sc second
#define MOD 1000000000

using namespace std;
int N;
vector<pair<int, bool> > graph[10003];
set<int> incoming[10003];
int bfsColor[10003];
int reacheble[10003];
char isConnected[10001][10001];

set<int> sources;

long long memoo[10003];


bool Tsort(vector<int> &ordered){
    set<int> processed;

    while (sources.size() > 0 ){
        int S = *sources.begin();
        sources.erase(sources.begin());
        ordered.push_back(S);
        processed.insert(S);
#ifdef DEBUG
            printf (">Processing vertex %d\n", S);
#endif
        if ( S == N ) return true;
        for(vector<pair<int,bool> > :: iterator it = graph[S].begin(); it != graph[S].end(); ++it){
            if ( it->second == false ) continue;
            it->second = false;

            bool hasIncoming = false;
#ifdef DEBUG
            printf ("\t>Checking neighbour %d\n", it->fs);
#endif
            for (set<int> :: iterator subIter = incoming[it->fs].begin();subIter != incoming[it->fs].end();++subIter){
                if ( processed.find(*subIter) == processed.end()){
                    hasIncoming = true;
                }
            }
            if ( !hasIncoming){
                sources.insert(it->fs);
            }
        }
    }

    return false;
}


long long calc(int index, vector<int> &ordered){
    if ( ordered[index] == N ) return 1LL;
    long long &ref = memoo[ordered[index]];
    vector<long long> dp(ordered.size(), 0);
    for (int i=0;i<ordered.size();++i){
        if ( ordered[i] == 1){
            dp[i] = 1;
        }
    }
    for (int i=0;i<ordered.size();++i){
        for (int j=0;j<i;++j){
            if ( isConnected[ordered[j]][ordered[i]]){
                dp[i] += dp[j];
#ifdef DEBUG
                printf ("> dp[%d] = %d\n", i, dp[i]);
#endif
                dp[i] %= MOD;
            }
        }
    }
    for (int i=0;i<ordered.size();++i){
        if ( ordered[i] == N ) return dp[i];
    }
    return 0LL;
}

long long calc2(int node){
    if ( node == N ) return 1LL;

    long long &ref = memoo[node];
    if ( ref != -1 ) return ref;

    long long sum = 0LL;
    for (int i=0;i<graph[node].size();++i){
        sum+=calc2(graph[node][i].fs);
        sum%=MOD;
    }
    return sum;
}

int main(void){
    int m,a,b;
    scanf("%d %d", &N, &m);
    vector<bool> hasIncoming(N+1, false);
    for (int i=0;i<m;++i){
        scanf("%d %d", &a, &b);
        graph[a].push_back(make_pair(b, true));
        incoming[b].insert(a);
        isConnected[a][b] = 'x';
        hasIncoming[b] = true;
    }

//    for (int i=1;i<N;++i){
//        if ( !hasIncoming[i] ) {
//#ifdef DEBUG
//            printf ("Source: %d\n", i);
//#endif
//            if (i == 1)sources.insert(i);
//        }
//    }

    if ( !hasIncoming[1]) sources.insert(1);

    vector<int> ordered;
    bool ok = Tsort(ordered);
#ifdef DEBUG
    printf (">>>");
    for (int i=0;i<ordered.size();++i) printf (" %d ", ordered[i]);
    printf ("\n");
#endif
    for (int i=0;i<=10000;++i)memoo[i] = -1;
    if ( !ok ){
        printf ("INFINITE PATHS\n");
    }else{
        printf ("%lld\n", calc(1, ordered));
    }

	return 0;
}
