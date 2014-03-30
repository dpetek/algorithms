/*
ID: dpetek11
LANG: C++
TASK: humble
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
#include <climits>
#include <cmath>
#include <cassert>
#define pb push_back
#define fs first
#define sc second
#define foreach(c,it) for(typeof(((c).begin())) it=((c).begin());(it)!=((c).end());++(it))
#define _sz(c) ((int)c.size())
#define cstr(s) ((s).c_str())
using namespace std;

#define MAX_VALUE (1LL<<31)

vector<long long> humble;
vector<int>primes;
priority_queue<pair<long long,int>, vector<pair<long long,int> > , greater<pair<long long,int> > >Q;
bool inQueue[105];
int n, m;

inline long long find(int &num){
    int L=0, H= humble.size()-1,M;
    long long biggest = humble[H];
    for (int i=0;i<30;++i){
        M = (L + H) / 2;
        if ( L == H ) break;
        if ( (long long)num <= MAX_VALUE / humble[M] && (long long)num * humble[M] <= biggest) L = M +1;
        else H = M;
    }
//    while(memoo[M] && M + 1 < humble.size()) ++M;
    return humble[M];
}

int main(void){
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
    int cnt = 0;

    int limit = 1;

    scanf("%d %d", &n, &m);

    int tmp;
    for (int i=0;i<n;++i){
        scanf("%d", &tmp);
        primes.pb(tmp);
    }

    humble.pb(1LL);
    while(humble.size() <= m + 1){
        set<long long> cand;
        for (int i=0;i<n;++i){
            if ( inQueue[i] ) continue;
            long long tmp = 0LL;
            long long num = find(primes[i]);
            if ( num > MAX_VALUE / primes[i]) continue;
            tmp = num * primes[i];

            Q.push(make_pair(tmp,i));
            inQueue[i] = true;
        }

        pair<long long, int> miny = Q.top();
        Q.pop();
        inQueue[miny.sc] = false;
        if ( miny.fs <= humble[humble.size()-1])continue;
        humble.pb(miny.fs);
    }
    printf ("%d\n", humble[m]);

    return 0;
}
