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

#define MOD 1000000000LL


int v[1000005];
int gapsi[1000005];
int gapsv[1000005];

int main(void){
    int N , K, gindex = 0;

    scanf ("%d %d", &N, &K);

    for (int i=0;i<N;++i){
        scanf("%d", &v[i]);
        if ( v[i] >= K) continue;
        gapsi[gindex] = i;
        gapsv[gindex] = K - v[i];
        ++gindex;
    }
    gindex = 0;

    long long power = 0LL;
    for (int i=0;i<N;++i){
        if ( v[i] <= K ) continue;
        while ( v[i] > K){
            if ( v[i]-K <= gapsv[gindex]){
                gapsv[gindex]-=v[i]-K;
                power+=((long long)((v[i]-K) * abs(i-gapsi[gindex])))%MOD;
                power%=MOD;
                if ( gapsv[gindex] == 0) ++gindex;
                v[i] = K;
            }else{
                v[i] -= gapsv[gindex];
                power+=((long long)(gapsv[gindex] *abs(i-gapsi[gindex])))%MOD;
                power%=MOD;
                ++gindex;
            }
        }
    }
    printf ("%lld\n", power%MOD);
    return 0;
}
