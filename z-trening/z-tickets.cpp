#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>

#define pb push_back
#define fs first
#define sc second

long long dp[100][11];

int main(void){
    int n;

    scanf ("%d", &n);

    for (int i=0;i<10;++i) dp[i][1] = 1LL;

    for (int i=2;i<=n/2;++i){
        for (int j=0;j<10;++j){
            for (int k=0;k<100;++k){
                if ( k - j < 0 ) continue;
                dp[k][i] += dp[k-j][i-1];
            }
        }
    }
    long long res = 0LL;
    for (int i=0;i<100;++i){
        res += dp[i][n/2] * dp[i][n/2];
    }
    printf ("%lld\n", res);

    return 0;
}
