/*
ID: dpetek11
LANG: C++
TASK: nocows
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
#define MOD 9901
int memoo[202][102];

int solve(int N, int K){
    int &ref = memoo[N][K];
    if ( ref != -1 ) return ref;
    if ( N <= 0 ) return 0;
    if ( N == 1 && K == 1) return 1;
    if ( N % 2 != 1 ) return 0;
    if ( N< 2*K-1)return 0;
    if ( N < 10 && N > 1<<K ) return 0;

    int cnt = 0;

    for (int left=1;left<N && N-left >= 1;left+=2){
        int right = N - left - 1;
        int right_comb = 0;
        for (int i=1;i<K-1;++i){
            right_comb += solve(right, i);
        }
        cnt+= ((2*solve(left, K-1) % MOD) * right_comb) % MOD;
        cnt%=MOD;
        cnt+= (solve(left, K-1) * solve(right, K-1)) % MOD;
        cnt%=MOD;
    }
    return ref = (cnt % MOD);
}

int main(void){
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    int N, K;

    for (int i=0;i<=200;++i)
        for (int j=0;j<=100;++j)
            memoo[i][j] = -1;

    memoo[1][1] = 1;
    scanf("%d %d", &N, &K);

    printf ( "%d\n", solve(N,K));

    return 0;
}
